//Number of Provinces

class Solution {
public:
    
    void dfs(int src, vector<int>&v,vector<vector<int>>&adj)
    {
        v[src]=1;
        for(auto i : adj[src])
            if(!v[i])
                dfs(i,v , adj);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j&&isConnected[i][j]==1)
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int cc=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,v);
                cc++;
            }
        }
        return cc;
    }
};