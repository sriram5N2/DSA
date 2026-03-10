#define vi vector <int>
#define vvi vector <vi>

class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        vector <vector <int>> adj (n);
        for (auto it : edges)
            adj[it[0]].push_back(it[1]), adj[it[1]].push_back(it[0]);

        vector <vvi> dp (n, vvi (n, vi ((1 << n), -1)));

        auto dfs = [&] (auto &&self, int a, int b, int mask) -> int {
            if (dp[a][b][mask] != -1) return dp[a][b][mask];

            if (a == b) return 1;

            int ans = -1000;
            for (auto it : adj[a]) if (it == b) ans = 2;

            for (auto it1 : adj[a]) {
                if (mask & (1 << it1)) continue;
                for (auto it2 : adj[b]) {
                    if (mask & (1 << it2)) continue;
                    if (label[it1] != label[it2]) continue;
                    ans = max (ans, 2 + self(self, it1, it2, mask | (1 << it1) | (1 << it2)));
                }
            }

            return dp[a][b][mask] = ans;
        };

        int ans = 1;

        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (label[i] == label[j])
                    ans = max (ans, dfs (dfs, i, j, (1 << i) | (1 << j)));

        return ans;
    }
};