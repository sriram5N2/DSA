class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<long long > dp(nums.size()),dp1(nums.size());
        dp[0]=nums[0];
        dp1[0]=nums[0];
        long long maxi=INT_MIN;
        maxi=max(maxi,dp[0]);
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=max({1LL*nums[i]*dp[i-1],dp1[i-1]*nums[i],1LL*nums[i]});
            dp1[i]=min({1LL*dp1[i-1]*nums[i],1LL*nums[i],nums[i]*dp[i-1]});
            maxi=max(maxi,dp[i]);
            maxi=max(maxi,dp1[i]);
        }
        return maxi;
    }
};