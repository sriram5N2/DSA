class Solution {
public:
    bool consecutiveSetBits(int n) {

        int cnt=0;
        int ans=0;
        while(n>0)
        {
            int r=n%2;
            if(r==1)
            cnt++;
            else
            cnt=0;
            if(cnt>=2)
            {
                ans++;
            }
           n=n/2;

        }
        if(ans==1) return true;
        return false;

        
    }
};