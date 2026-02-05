class Solution {
public:
    int jobScheduling(vector<int>& S, vector<int>& E, vector<int>& P) {

        vector<vector<int>> jobs;
        for(int i=0;i<S.size();i++)
        {
            jobs.push_back({E[i],S[i],P[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int> E1;
        for(auto job:jobs)
        {
            E1.push_back(job[0]);
        }
        int N=S.size();
        vector<int> dp(N+1);
        dp[0]=0;
        for(int i=1;i<=N;i++)
        {
            int idx=upper_bound(E1.begin(),E1.end(),jobs[i-1][1])-E1.begin();
            dp[i]=max(dp[i-1],jobs[i-1][2]+dp[idx]);

        }
        return dp[N];
        
    }
};