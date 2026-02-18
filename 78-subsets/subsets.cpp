class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int N=nums.size();
        vector<vector<int>> ans;
        for(int mask=0;mask<(1<<N);mask++)
        {
            vector<int> curr_set;
            for(int i=0;i<N;i++)
            {
                if(mask&(1<<i))
                curr_set.push_back(nums[i]);

            }
            ans.push_back(curr_set);
        }
        return ans;
        
    }
};