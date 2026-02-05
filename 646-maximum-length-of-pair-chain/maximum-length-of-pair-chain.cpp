class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int N=pairs.size();
        sort(pairs.begin(),pairs.end(),[](const vector<int> &a,const vector<int> &b)
        {
            return a[1]<b[1];
        });
        vector<int> R;
        for(auto pair:pairs)
        R.push_back(pair[1]);

        vector<int> dp(N+1,1);
        dp[0]=0;
        for(int i=1;i<=N;i++)
        {
            int idx=lower_bound(R.begin(),R.end(),pairs[i-1][0])-R.begin();
            dp[i]=max(dp[i-1],1+dp[idx]);
        }
        return dp[N];

        
    }
};