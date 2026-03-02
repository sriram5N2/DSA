class Solution {
public:
unordered_map<int,unordered_map<int,int>> dp;
int global=INT_MAX;
    int solve(int i,vector<vector<int>> &grid,int curr_or)
    {
        if(curr_or>=global) return 1e9;
        if(i>=grid.size())
        {
               global=min(global,curr_or);
               return curr_or;
        }
        if(dp[i].count(curr_or)) return dp[i][curr_or];
       int ans=1e9;
        for(int col=0;col<grid[0].size();col++)
            {
                int new_or=curr_or;
                
                    new_or=new_or|grid[i][col];
               ans=min(ans,solve(i+1,grid,new_or));
                    
                
            }
        return dp[i][curr_or]=ans;
    }
    int minimumOR(vector<vector<int>>& grid) {
      
        return solve(0,grid,0);
        
    }
};