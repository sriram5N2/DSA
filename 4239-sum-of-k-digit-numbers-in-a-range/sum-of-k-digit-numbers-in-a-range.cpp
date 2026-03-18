class Solution {
public:
long long power(long long a,long long b)
{
    long long ans=1;
    long long mod=1e9+7;
    while(b>0)
    {
        if(b&1)
        ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}
    int sumOfNumbers(int l, int r, int k) {
long long mod=1e9+7;
        long long total=(r-l+1);
        long long digit_sum=((total*(l+r))/2)%mod;
        long long first_=power(total,k-1);
        long long weights=power(10,k);

        long long env=power(9,mod-2);
        long long sum=((weights-1+mod)%mod*env)%mod;
        long long result=digit_sum;
        result=(result*first_)%mod;
        result=(result*sum)%mod;
        return result;


        
    }
};