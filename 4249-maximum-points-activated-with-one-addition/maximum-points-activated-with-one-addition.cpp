class Solution {
public:
  class DSU{
    public:
    vector<int> parent;
    vector<int> sz;
    DSU(int n)
    {
        parent.resize(n);
        sz.assign(n,1);
        for(int i=0;i<n;i++)
        parent[i]=i;
    }
    int find(int u)
    {
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }
    void unite(int i,int j)
    {
        int up=find(i);
        int vp=find(j);
        if(sz[up]<sz[vp]) swap(up,vp);
        parent[vp]=up;
        sz[up]+=sz[vp];
    }
  };
    int maxActivated(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0) return 0;

    DSU dsu(n);
        unordered_map<int,int> lastX,lastY;
        for(int i=0;i<n;i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            if(lastX.count(x))
            {
                dsu.unite(lastX[x],i);

            }
            else
            lastX[x]=i;
            if(lastY.count(y))
            {
                dsu.unite(lastY[y],i);

            }
            else
            lastY[y]=i;
        }
        vector<int> component_sizes;
        for(int i=0;i<n;i++)
        {
            if(dsu.find(i)==i)
            component_sizes.push_back(dsu.sz[i]);
        }
        sort(component_sizes.rbegin(),component_sizes.rend());
        int ans=0;
        ans=1+component_sizes[0];
        if(component_sizes.size()>1)
        {
            ans+=component_sizes[1];
        }
        return ans;
        
    }
};