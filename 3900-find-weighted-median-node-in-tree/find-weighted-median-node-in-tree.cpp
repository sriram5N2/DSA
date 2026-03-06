class Solution {
public:

 void dfs(int node, int parent, int depth, long long accWeight,
             vector<int> &depths, vector<long long> &cumulativeWeight,
             vector<vector<pair<int, int>>> &graph, vector<vector<int>> &up) {
        depths[node] = depth;
        cumulativeWeight[node] = accWeight;
        up[node][0] = parent;

        for (auto &[neighbor, weight] : graph[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, accWeight + weight, depths, cumulativeWeight, graph, up);
            }
        }
    }

      void preprocess(int n, int maxPower, vector<vector<int>> &up) {
        for (int p = 1; p <= maxPower; ++p) {
            for (int node = 0; node < n; ++node) {
                int par = up[node][p - 1];
                if (par != -1) {
                    up[node][p] = up[par][p - 1];
                }
            }
        }
    }

     int lift(int u, int diff, const vector<vector<int>> &up) {
        while (diff > 0) {
            int step = log2(diff);
            u = up[u][step];
            diff -= (1 << step);
        }
        return u;
    }
    int lca(int u, int v, int maxPower, const vector<int> &depths, const vector<vector<int>> &up) {
        if (depths[u] > depths[v]) swap(u, v);
        v = lift(v, depths[v] - depths[u], up);

        if (u == v) return u;

        for (int i = maxPower; i >= 0; --i) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }
      long long dist(int u, int v, int maxPower, const vector<int> &depths,
                   const vector<long long> &cumulativeWeight, const vector<vector<int>> &up) {
        int common = lca(u, v, maxPower, depths, up);
        return cumulativeWeight[u] + cumulativeWeight[v] - 2 * cumulativeWeight[common];
    }
   int findWeightedMedian(int u, int v,
                           const vector<int> &depths,
                           const vector<long long> &cumulativeWeight,
                           const vector<vector<int>> &up,
                           int maxPower) {

  if(u==v) return u;
  int ancestor=lca(u,v,maxPower,depths,up);
  int e_u_to_v=depths[u]+depths[v]-2*depths[ancestor];
  int e_u_to_lca=depths[u]-depths[ancestor];
  long long tot_dist=cumulativeWeight[u]+cumulativeWeight[v]-2*cumulativeWeight[ancestor];

   int low = -1, high =  e_u_to_v + 1, answer = -1;

        while (high - low > 1) {
            int mid = (low + high) / 2;
            int x, lca_ux;
            if (mid <= e_u_to_lca) {
                x = lift(u, mid, up);
                lca_ux = x;
            } else {
                x = lift(v,  e_u_to_v - mid, up);
                lca_ux = ancestor;
            }

            long long d = cumulativeWeight[u] + cumulativeWeight[x] - 2 * cumulativeWeight[lca_ux];
            if (2 * d >= tot_dist) {
                answer = x;
                high = mid;
            } else {
                low = mid;
            }
        }

        return answer;


                           }
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int max_n=32-__builtin_clz(n);
    
        vector<vector<pair<int,int>>> graph(n);
        for(auto e:edges)
        {
            int u=e[0],v=e[1],w=e[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        vector<int> depths(n);
        vector<long long> cumulative_weights(n);
        vector<vector<int>> up(n,vector<int>(max_n+1,-1));
        dfs(0,-1,0,0,depths,cumulative_weights,graph,up);
        preprocess(n,max_n,up);

        vector<int> result;
        for (const auto &q : queries) {
            int u = q[0], v = q[1];
            result.push_back(findWeightedMedian(u, v, depths,cumulative_weights, up,max_n));
        }

        return result;

        
    }
};