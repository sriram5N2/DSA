class Solution {
public:
    int longestAlternating(vector<int>& nums) {

      //  dp[i][j][k]  i -> curr_index we are standing at   j-> the last comparison whether it is smaller or larger like that k-> defines whether you have used the skip chance or not 
      int n=nums.size();
      vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,1)));

     
      for(int i=1;i<n;i++)
      {
        if(nums[i]>nums[i-1])
        {
            dp[i][1][0]=dp[i-1][0][0]+1;
            dp[i][1][1]=max(dp[i][1][1],dp[i-1][0][1]+1);// connectiog previously skipped case to the existiing one 
        }
        if(nums[i]<nums[i-1])
        {
            dp[i][0][0]=dp[i-1][1][0]+1;
            dp[i][0][1]=max(dp[i-1][1][1]+1,dp[i][0][1]);// connectiog previously skipped case to the existiing one 
        }
        if(i-2>=0)
        {
            if(nums[i]>nums[i-2])
            dp[i][1][1]=max(dp[i][1][1],dp[i-2][0][0]+1);
            if(nums[i]<nums[i-2])
            dp[i][0][1]=max(dp[i][0][1],dp[i-2][1][0]+1);

          
        }
      
        
      }
      int ans=INT_MIN;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            ans=max(ans,dp[i][j][k]);
        }
      }
      return ans;
        
    }
};