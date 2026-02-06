class Solution {
public:
    int distinctSubseqII(string s) {

        long long current_add=0,Total=0;
        int MOD=1e9+7;
        vector<long long> freq(26,0);
        for(int i=0;i<s.size();i++)
        {
            int idx=s[i]-'a';
            current_add=(Total+1)%MOD;
            long long actual_new=(current_add-freq[idx]+MOD)%MOD;
            Total=(Total+actual_new)%MOD;
            freq[idx]=(current_add)%MOD;
        }
        return (int)Total%MOD;
        
    }
};