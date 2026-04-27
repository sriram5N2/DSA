class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int N=nums.size();
        int ans=0;
        for(int i=1;i<(1<<N);i++)
            {
                vector<int> subset;
                int subset_sum=0;
                map<int,int> mp;
                for(int j=0;j<N;j++)
                    {
                        if(i&(1<<j))
                        {
                            subset.push_back(j);
                            mp[j]++;
                            subset_sum+=nums[j];
                        }
                    }
                if(subset_sum%2==0)
                {
                    if(subset.size()==1) {
                        ans++;
                    continue;}
                    vector<vector<int>> adj(N);
                    int root=-1;
                    for(auto e:edges)
                        {
                            int x=e[0];
                            int y=e[1];
                            if(mp[x]&&mp[y])
                            {
                                root=x;
                                adj[x].push_back(y);
                                adj[y].push_back(x);
                            }
                        }
                  int cnt=0;
                   queue<int> q;
                     vector<int> vis(N,0);
                    if(root!=-1){
                    q.push(root);
                    cnt++;
                    vis[root]=1;}
                    while(!q.empty())
                        {
                            auto node=q.front();
                            q.pop();
                            
                            for(auto e:adj[node])
                                {
                                    if(!vis[e])
                                    {
                                        vis[e]=1;
                                        q.push(e);
                                        cnt++;
                                    }
                                }
                            
                            
                        }
                    if(cnt==subset.size())
                        ans++;
                  
                    
                    
                }
                
                
            }
        return ans;
        
    }
};