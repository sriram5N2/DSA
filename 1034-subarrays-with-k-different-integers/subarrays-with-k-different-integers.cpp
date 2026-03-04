class Solution {
public:
int fun(vector<int> &nums,int k)
{
    unordered_map<int,int> mp1;
    int left=0;
    int ans=0;
    for(int right=0;right<nums.size();right++)
    {
        mp1[nums[right]]++;
        while(mp1.size()>k)
        {
            if(--mp1[nums[left]]==0) mp1.erase(nums[left]);
            left++;
        }
        ans+=(right-left+1);

    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
       return (fun(nums,k)-fun(nums,k-1));
        
    }
};