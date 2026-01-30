class Solution {
public:
    int lengthOfLongestSubstring(string s) {

       map<char,int> mp;
        int i=0;
        int j=0;
        int n=s.size();
        if(s==" ") return 1;
        int  ans=0;
        while(i<n)
        {
           
            if(mp[s[i]]>=j)
            {
                j=mp[s[i]];
              
            }
             mp[s[i]]=i+1;
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
        
    }
};