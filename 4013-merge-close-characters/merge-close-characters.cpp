class Solution {
public:
    string mergeCharacters(string s, int k) {
        string result;
        result.reserve(s.size());
        int cnt[26]={0};
        for(int i=0;i<s.size();i++)
        {
            if(cnt[s[i]-'a']>0) continue;

            result.push_back(s[i]);
            cnt[s[i]-'a']++;
            if(result.size()>k)
            {
                char drop=result[result.size()-k-1];
                cnt[drop-'a']--;
            }
        }
        return result;
        
    }
};