class Solution {
public:
  void solve(int indx,vector<int> &nums, vector<vector<int>> &ans,vector<int> &temp)
  {
    if(indx>=nums.size()) {ans.push_back(temp); return;}
    temp.push_back(nums[indx]);
    solve(indx+1,nums,ans,temp);
    temp.pop_back();
    solve(indx+1,nums,ans,temp);

  }
    vector<vector<int>> subsets(vector<int>& nums) {
        int N=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
       solve(0,nums,ans,temp);
        return ans;
        
    }
};