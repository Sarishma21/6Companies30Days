class Solution {
	public:
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool> q1ed(V, false), q2ed(V, false);
        queue<int> q1, q2;

        q1.push(c);
        q1ed[c] = true;

        q2.push(d);
        q2ed[d] = true;

        while(!q1.empty() && !q2.empty()) {
            int cReached = q1.front(); q1.pop();
            int dReached = q2.front(); q2.pop();

            if(q2ed[cReached] || q1ed[dReached]) {
                return 0;
            }

            for(auto node: adj[cReached]) {
                if(q1ed[node] || (cReached == c && node == d)) continue;
                q1.push(node);
                q1ed[node] = true;
            }

            for(auto node: adj[dReached]) {
                if(q2ed[node] || (dReached == d && node == c)) continue;
                q2.push(node);
                q2ed[node] = true;
            }
        }
        return 1;
    }
};