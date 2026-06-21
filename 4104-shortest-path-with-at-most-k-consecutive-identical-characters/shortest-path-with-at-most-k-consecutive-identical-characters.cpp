class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<>> pq;
        pq.push({{0, 0}, 1});
        long long ans = LONG_MAX;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LONG_MAX));
        dist[0][1] = 0;
        
        while(!pq.empty())
        {
            long long wt = pq.top().first.first;
            long long node = pq.top().first.second;
            long long cnt = pq.top().second;
            pq.pop();
          
            if(wt > dist[node][cnt]) continue;
            
            for(auto it : adj[node])
            {
                long long v = it.first;
                long long w = it.second;
                
               
                int next_cnt = (labels[node] == labels[v]) ? cnt + 1 : 1;
                
                if(next_cnt <= k)
                {
                    if(dist[v][next_cnt] > wt + w)
                    {
                        dist[v][next_cnt] = wt + w;
                        pq.push({{wt + w, v}, next_cnt});
                    }
                } 
            }
        }
        
        for(int i = 0; i <= k; i++)
        {
            ans = min(ans, dist[n - 1][i]);
        }
        
        return (ans == LONG_MAX) ? -1 : ans;
    }
};