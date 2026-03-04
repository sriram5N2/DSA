class Solution {
public:
int fun(vector<int> &nums,int k)
{
    unordered_map<int,int> mp1,mp2;
    int left=0,leftv=0;
    int ans=0;
    for(int right=0;right<nums.size();right++)
    {
        mp1[nums[right]]++;
        while(mp1.size()>k)
        {
            if(--mp1[nums[left]]==0) mp1.erase(nums[left]);
            left++;
        }
        mp2[nums[right]]++;
       while(mp2.size()>=k)
       {
        if(--mp2[nums[leftv]]==0)
        mp2.erase(nums[leftv]);
        leftv++;


       }
        ans+=max(leftv-left,0);

    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      
       return fun(nums,k);
        
    }
};