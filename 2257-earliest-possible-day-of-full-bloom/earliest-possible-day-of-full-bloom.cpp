class Solution {
public:
    int earliestFullBloom(vector<int>&pt,vector<int>& gt) {

       // sort(gt.rbegin(),gt.rend());
        vector<pair<int,int>> arr;
         int n=pt.size();
        for(int i=0;i<n;i++)
        arr.push_back({gt[i],i});
        sort(arr.rbegin(),arr.rend());

        int tot=0;
        int curr=0;
       
        for(int i=0;i<n;i++)
        {
            tot=max(tot,curr+pt[arr[i].second]+arr[i].first);
            curr+=pt[arr[i].second];
        }
        return tot;
        
    }
};