class Solution {
public:
 void solve(string s,char x,char y,int &maxi)
 {
    map<int,int> mp;
    mp[0]=-1;
    int sum=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==x)
        sum++;
        else if(s[i]==y)
        sum--;
        else
        {
            mp.clear();
            mp[0]=i;
            sum=0;
            continue;
        }
        if(mp.find(sum)!=mp.end())
        maxi=max(maxi,i-mp[sum]);
        else
        mp[sum]=i;


    }
 }
    int longestBalanced(string s) {

        int n=s.size();

        int maxi=1;
        int len=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            len++;
            else
            len=1;
            maxi=max(maxi,len);
        }

        solve(s,'a','b',maxi);
        solve(s,'a','c',maxi);
        solve(s,'b','c',maxi);

        map<pair<int,int>,int> mp;
        int count[3]={0};
    mp[{0,0}]=-1;
    for(int i=0;i<s.size();i++)
    {
          count[s[i]-'a']++;
          int countAB=count[0]-count[1];
          int countBC=count[1]-count[2];
          if(mp.find({countAB,countBC})!=mp.end())
          maxi=max(maxi,i-mp[{countAB,countBC}]);
          else
          mp[{countAB,countBC}]=i;

    }
    return maxi;


        
    }
};