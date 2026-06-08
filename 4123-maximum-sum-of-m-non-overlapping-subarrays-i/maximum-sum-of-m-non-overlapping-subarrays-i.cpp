class Solution {
public:
   const long long INF=-1e14;
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n=nums.size();


        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++)
        {
            pref[i+1]=nums[i]+pref[i];
        }
       vector<long long> prev_dp(n+1,0);
       
long long ans=INF;
        for(int j=1;j<=m;j++)
        {
            vector<long long> curr_dp(n+1,INF);
            deque<long long> dq;
            for(int i=1;i<=n;i++)
            {
                curr_dp[i]=curr_dp[i-1];
                int st=i-l;
                if(st>=0&&prev_dp[st]!=INF)
                {
                    long long new_val=prev_dp[st]-pref[st];
                    while(!dq.empty())
                    {
                            long long old_val=prev_dp[dq.back()]-pref[dq.back()];
                            if(new_val>=old_val)
                            {
                                dq.pop_back();
                            }
                            else
                            break;


                    }
                    dq.push_back(st);
                }
                while(!dq.empty()&&dq.front()<i-r)
                {
                    dq.pop_front();
                }
                if(!dq.empty())
                {
                    long long total_val=pref[i]-pref[dq.front()];
                    curr_dp[i]=max(curr_dp[i],total_val+prev_dp[dq.front()]);
                }

            }
            ans=max(ans,curr_dp[n]);
            prev_dp=curr_dp;

        }
        return ans;
    }
};