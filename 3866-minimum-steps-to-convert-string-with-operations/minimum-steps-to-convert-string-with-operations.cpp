class Solution {
public:
int n;
vector<int> dp;
 int countOps(string s1,string s2)
 {
    int save[26][26]={};
    int cnt=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]==s2[i]) continue;
        if(save[s2[i]-'a'][s1[i]-'a']>0)
        {
            save[s2[i]-'a'][s1[i]-'a']--;
        }
        else
        {
            cnt++;
            save[s1[i]-'a'][s2[i]-'a']++;
        }

    }
    return cnt;
 }
   int dfs(int indx,string word1,string word2)
   {
    if(indx==n) return 0;
    if(dp[indx]!=-1) return dp[indx];
    int ans=INT_MAX;
    for(int j=indx;j<n;j++)
    {
        string s1=word1.substr(indx,j-indx+1);
        string s2=word2.substr(indx,j-indx+1);
       int  op1= countOps(s1,s2);

       reverse(s1.begin(),s1.end());

       int op2=countOps(s1,s2);
       int remPart=dfs(j+1,word1,word2);

       ans=min(ans,remPart+min(op1,1+op2));


    }
    return dp[indx]=ans;
   }
    int minOperations(string word1, string word2) {
        n=word1.size();
       dp.assign(n,-1);
      return dfs(0,word1,word2);
    }
};