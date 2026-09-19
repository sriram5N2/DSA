class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n,0);
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty()&&arr[i]>=arr[st.top()])
            {
                st.pop();
            }
            if(st.empty())
            ans[i]=0;
            else
            ans[i]=st.top()-i;
           st.push(i);
            
        }
       return ans;
        
    }
};