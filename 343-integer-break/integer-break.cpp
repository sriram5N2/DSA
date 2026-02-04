class Solution {
public:
    int solve(int n)
    {
        if(n==1) return 1;
        int pro=1;
        for(int i=1;i<n;i++)
        {
            pro=max(i*solve(n-i),pro);

        }
        return pro;
    }
    int integerBreak(int n) {

       int dp[60]={0};
       dp[1]=0;
       dp[2]=1;
       dp[3]=2;
       dp[4]=4;
       for(int i=5;i<=n;i++)
       {
        for(int j=1;j<i;j++)
        {
            int curr_best=max(j*(i-j),j*dp[i-j]);
            dp[i]=max(dp[i],curr_best);
            
        }
        
       }
       return dp[n];
        
    }
};