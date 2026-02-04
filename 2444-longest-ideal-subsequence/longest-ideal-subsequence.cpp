class Solution {
public:
    int longestIdealString(string s, int k) {
       int n=s.size();
       vector<int> dp(26,INT_MIN);
       dp[s[0]-'a']=1;
       for(int i=1;i<n;i++)
       {
           int  curr_char=s[i]-'a';
           int best_prev=0;
           for(int ch=max(curr_char-k,0);ch<=min(curr_char+k,25);ch++)
          best_prev=max(best_prev,dp[ch]);
          dp[curr_char]=1+best_prev;

       }
       int ans=1;
       for(int i=0;i<26;i++)
       {
        ans=max(ans,dp[i]);
       }
       return ans;
       
        
    }
};