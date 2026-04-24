class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int right=0,left=0;
        int ans=0;
        int n=s.size();
        while(right<n)
        {
            while(left<=right&&mp[s[right]]==1)
            {
                mp[s[left]]--;
                left++;
            }
            mp[s[right]]++;
            ans=max(ans,right-left+1);
            right++;

        }
        return ans;
        
    }
};