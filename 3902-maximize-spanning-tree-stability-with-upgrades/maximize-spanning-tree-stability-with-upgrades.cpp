class UnionFind {
public:
    vector<int> rank, root;
    UnionFind(int n) : rank(n, 1), root(n) {
        iota(root.begin(), root.end(), 0);
    }
    int find(int x) {
        return root[x] == x ? x : root[x] = find(root[x]);
    }
    bool unionSet(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] > rank[ry]) {
            root[ry] = rx;
        } else if (rank[rx] < rank[ry]) {
            root[rx] = ry;
        } else {
            root[rx] = ry;
            rank[ry] += 1;
        }
        return true;
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    vector<int> baseRank;
    vector<int> baseRoot;
    int mini_s = INT_MAX;

    // Added parameters so the function can actually see the data
    bool check(int mid, int n, int k, const vector<vector<int>>& edges) {
        if (mid > mini_s) return false;

        UnionFind uf(n);
        uf.rank = baseRank;
        uf.root = baseRoot;

        vector<pair<int, int>> upgrade;
        for (auto& e : edges) {
            if (e[3]) continue; // Skip "must-have" as they are already in baseRoot
            
            if (e[2] >= mid) {
                uf.unionSet(e[0], e[1]);
            } else if (e[2] * 2 >= mid) {
                upgrade.push_back({e[0], e[1]});
            }
        }

        int r = k;
        for (auto& p : upgrade) {
            if (uf.isConnected(p.first, p.second)) continue;
            if (r <= 0) break; // Use break instead of return false here to check connectivity after
            uf.unionSet(p.first, p.second);
            r--;
        }

        // Final Connectivity Check
        int root0 = uf.find(0);
        for (int i = 1; i < n; ++i) {
            if (uf.find(i) != root0) return false;
        }
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UnionFind initial_uf(n);
        int max_s = 0;
        mini_s = INT_MAX; 
        bool hasMust = false;

        for (auto& e : edges) {
            max_s = max(max_s, e[2]);
            if (e[3]) {
                hasMust = true;
                mini_s = min(mini_s, e[2]);
                if (!initial_uf.unionSet(e[0], e[1])) return -1; // Cycle in must-haves
            }
        }
        
        if (!hasMust) mini_s = INT_MAX; // No restriction if no must-haves exist

        baseRank = initial_uf.rank;
        baseRoot = initial_uf.root;

        int left = 0, right = max_s * 2;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, n, k, edges)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};