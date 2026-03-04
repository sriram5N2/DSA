class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {

        vector<int> basis(31,0);
        
        for(auto el:nums)
        {
            for(int i=30;i>=0;i--)
            {
                if(!(el&(1<<i))) continue;
                if(!basis[i])
                {
                    basis[i]=el;
                    break;
                }
                el^=basis[i];
            }

        }
        int ans=0;
        for(int i=30;i>=0;i--)
        {
            ans=max(ans,ans^basis[i]);
        }
        return ans;
        
    }
};