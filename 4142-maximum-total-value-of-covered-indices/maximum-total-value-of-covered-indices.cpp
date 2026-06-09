class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {

       long long ans=0;
        int n=s.size();
        for(int i=0;i<s.size();i++)
            {
                if(s[i]=='1')
                {
                    if(i>0&&s[i-1]=='0')
                    {
                       int mini=nums[i-1];
                        ans+=(1LL*nums[i-1]);
                        while(i<n&&s[i]=='1')
                            {
                                ans+=nums[i];
                             
                                mini=min(mini,nums[i]);
                                i++;
                            }
                        ans-=mini;
                        
                    }
                    else
                        ans+=(1LL*nums[i]);
                }
            }
        return ans;
        
    }
};