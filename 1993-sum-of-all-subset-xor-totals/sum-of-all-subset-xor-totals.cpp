class Solution {
public:
    int subsetXORSum(vector<int>& nums) {

        int N=nums.size();
        vector<int> dp(1<<N,0);
        int ans=0;
        for(int mask=1;mask<(1<<N);mask++)
        {
            int curr_xor=0;
            for(int i=0;i<nums.size();i++)
            {
                if(mask&(1<<i))
                curr_xor^=nums[i];
            }
            ans+=curr_xor;
        }
        return ans;

        
    }
};