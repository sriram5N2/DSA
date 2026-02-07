class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {

        int MOD=1e9+7;
        long long ans=1;
        bool has_One=false;
        int last_pos_1=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i])
            {
                if(last_pos_1!=-1)
                {
                    ans=(ans*(i-last_pos_1))%MOD;
                }
                has_One=true;
                last_pos_1=i;
            }
        }
        return (has_One?ans:0);
        
    }
};
