struct TrieNode {
    TrieNode* child[2];
    int count;
    
    TrieNode() {
        child[0] = child[1] = nullptr;
        count = 0;
    }
};
class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode();
    }
    void insert(int x)
    {
        TrieNode* node=root;
        for(int i=16;i>=0;i--)
        {
            int bit=(x>>i)&1;
            if(!node->child[bit])
            {
                node->child[bit]=new TrieNode();
            }
            node=node->child[bit];
            node->count++;
        }

    }
    void remove(int x)
    {
        TrieNode* node=root;
        for(int i=16;i>=0;i--)
        {
            int bit=(x>>i)&1;
            node=node->child[bit];
            node->count--;
        }

    }
    int maxXor(int x)
    {
        TrieNode* node=root;
        int res=0;
        for(int i=16;i>=0;i--)
        {
            int bit=(x>>i)&1;
            int desired=1-bit;
            if(node->child[desired]&&node->child[desired]->count>0)
            {
                res|=(1<<i);
                node=node->child[desired];
            }
            else
            node=node->child[bit];
        }
        return res;

    }
};



class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        int n=nums.size();
       vector<int> prefix(n+1,0);
       int l=0;
       for(int i=0;i<n;i++)
       {
        prefix[i+1]=prefix[i]^nums[i];
       }
       Trie trie;
       trie.insert(prefix[0]);
       multiset<int> ms;
       int ans=0;

       for(int right=0;right<n;right++)
       {
        ms.insert(nums[right]);
        while(!ms.empty()&&(*ms.rbegin()-*ms.begin())>k)
        {
            ms.erase(ms.find(nums[l]));
            trie.remove(prefix[l++]);
        }
        ans=max(ans,trie.maxXor(prefix[right+1]));
        trie.insert(prefix[right+1]);



       }
       return ans;
        
    }
};