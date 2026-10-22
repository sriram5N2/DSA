class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix_sum(n,0);
        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(prefix_sum[i]==k)
            {
                ans++;

            }
            if(mp.find(prefix_sum[i]-k)!=mp.end())
            {
                ans+=mp[prefix_sum[i]-k];
            }
            mp[prefix_sum[i]]++;
        }
        return ans;
        
    }
};