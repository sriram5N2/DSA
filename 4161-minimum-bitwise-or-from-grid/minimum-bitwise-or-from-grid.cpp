class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {

        int ans=0;
        int n=grid.size();
        for(int bit=17;bit>=0;bit--)
        {
            vector<vector<int>> temp(n);
            bool flag=true;
            for(int i=0;i<grid.size();i++)
            {
                for(auto val:grid[i])
                {
                    if((val&(1<<bit))==0)
                    {
                        temp[i].push_back(val);
                    }
                }
                if(temp[i].empty())
                {
                    ans=ans|(1<<bit);
                    flag=false;
                    break;
                }

            }
            if(flag)
            {
                grid=temp;

            }
        }
        return ans;
        
    }
};