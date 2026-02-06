long long  rec(int idx,int parity,vector<int>&nums,vector<vector<long long>>&dp){
    int n=nums.size();
    if(idx>=n)return 0;

    if(dp[idx][parity%2]!=-1e18)return dp[idx][parity%2];

    long long int old=-2e18,new_subarray=-2e18;
    if(parity%2){
        old = 1LL*-nums[idx] + rec(idx+1,parity+1,nums,dp);
    }
    else{
        old =1LL*nums[idx]+rec(idx+1,parity+1,nums,dp);
    }

    new_subarray=1LL*nums[idx]+rec(idx+1,1,nums,dp);
    

    return dp[idx][parity%2]=max(old,new_subarray);
}
class Solution {
public:

    long long maximumTotalCost(vector<int>& nums) {

        int n=nums.size();

        vector<vector<long long>>dp(n,vector<long long>(2,-1e18));
        return rec(0,0,nums,dp);
        
    }
};