class Solution {
public:
    bool wordBreak(string s, vector<string>& A) {
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
    set<string> m(A.begin(),A.end());
        for(int i=1;i<=n;i++)
        {
            //string temp;
            for(int j=0;j<=i-1;j++)
            {
              
                 if(dp[j]&&m.find(s.substr(j,i-j))!=m.end())
                    dp[i]=true;
            }
          
        }
        return dp[n];
    }
};