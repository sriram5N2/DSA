class Solution {
public:
    int maxScore(vector<int>& a, int k) {

        int total_pts=0;
        for(auto pts:a)
        {
            total_pts+=pts;
        }
        int n=a.size();
        int sz=n-k;
        long long mini_pts=INT_MAX;
        long long sum=0;
        for(int i=0;i<sz;i++)
        {
            sum+=a[i];
        }
        mini_pts=sum;
        for(int i=sz;i<n;i++)
        {
            sum-=a[i-sz];
            sum+=a[i];
            mini_pts=min(mini_pts,sum);
        }
        return total_pts-mini_pts;
        
    }
};