class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {

        long long  even1=0,odd1=0,odd2=0,even2=0;
        int MOD=1e9+7;
        for(auto it:nums)
        {
            if(it%2==0)
            {
                long long nevn1=(odd1+odd2+1)%MOD;
                long long nevn2=even1%MOD;
                even1=(nevn1+even1)%MOD;
                even2=(even2+nevn2)%MOD;
            }
            else
            {
                long long nodd1=(even1+even2+1)%MOD;
                long long nodd2=odd1;
                odd1=(odd1+nodd1)%MOD;
                odd2=(odd2+nodd2)%MOD;

            }
        }
        long long ans=(even1+even2+odd1+odd2)%MOD;
        return ans;
        
    }
};