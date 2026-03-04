class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        unordered_map<int,int> mp1,mp2;
        long long ans=0;
        int leftd=0,leftv=0,vcount=0;
        for(int right=0;right<nums.size();right++)
        {
            mp1[nums[right]]++;
            while(mp1.size()>k)
            {
                if(--mp1[nums[leftd]]==0)
                mp1.erase(nums[leftd]);
                leftd++;
            }
            if(++mp2[nums[right]]==m) vcount++;
            while(vcount>=k)
            {
                if(mp2[nums[leftv]]--==m)
                vcount--;
                leftv++;
            }
            if(leftv>leftd) ans+=(leftv-leftd);
        }
        return ans;
        
    }
};