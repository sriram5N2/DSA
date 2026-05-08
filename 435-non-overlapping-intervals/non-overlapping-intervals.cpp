class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            return a[1]<b[1];
        });

        int last_interval=intervals[0][1];
         int n=intervals.size();
        int ans=1;
        for(int i=1;i<intervals.size();i++)
        {

            if(intervals[i][0]>=last_interval)
            {
                last_interval=max(intervals[i][1],last_interval);
                ans++;
            }
            

        }
        for(auto it:intervals)
        {
           for(auto val:it)
           {
            cout<<val<<" ";
           }
           cout<<endl;

        }
        cout<<endl;
        return n-ans;



        
    }
};