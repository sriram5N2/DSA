class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-20000));
        long long ans=INT_MIN;
        dp[0][0]=arr[0];
        dp[0][1]=arr[0];
        ans=max(ans,dp[0][0]);
  
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(1LL*arr[i]+dp[i-1][0],1LL*arr[i]);
            dp[i][1]=max(dp[i-1][0],arr[i]+dp[i-1][1]);
            ans=max({ans,dp[i][0],dp[i][1]});
           
        }
        return ans;
        
    }
};