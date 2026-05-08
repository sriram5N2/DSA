class Solution {
public:
    int characterReplacement(string s, int k) {

        map<char,int> mp;
        int ans=0;
        int i=0,n=s.size(),j=0;;
        int max_freq=0;
        while(i<n)
        {
            mp[s[i]]++;

            max_freq=max(max_freq,mp[s[i]]);
            while((i-j+1)-max_freq>k)
            {
                mp[s[j]]--;
                j++;
            }
           
            i++;
             ans=max(ans,i-j);
        }
        return ans;
        
    }
};