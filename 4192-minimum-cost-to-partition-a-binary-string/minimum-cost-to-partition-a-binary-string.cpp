class Solution {
public:
vector<long long> prefix;
long long enc,flat;
long long dfs(int l,int r)
{
    int ones=prefix[r+1]-prefix[l];
    int sz=r-l+1;
    long long cost=INT_MAX;
    if(ones==0)
    {
        cost=flat;

    }
    else
    {
        cost=1LL*sz*ones*enc;
    }
    if(sz%2==0)
    {
        int mid=(l+r)/2;
        cost=min(cost,dfs(l,mid)+dfs(mid+1,r));
    }
    return cost;
}
    long long minCost(string s, int encCost, int flatCost) {
   int n=s.size();
  prefix.assign(n+1,0);
  enc=encCost;
  flat=flatCost;
   for(int i=0;i<n;i++)
   {
    
    prefix[i+1]=prefix[i]+(s[i]=='1');



   }
        return dfs(0,n-1);
        
    }
};