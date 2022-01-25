class Solution {
public:
    bool isCyclic(int N, vector<int> adj[],vector<int> &res) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); 
            res.push_back(node);
	        q.pop(); 
	        cnt++; 
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt == N) return false; 
	    return true; 
	}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int>res;
        for(auto it: prerequisites)
            adj[it[1]].push_back(it[0]);
        
        if( isCyclic(numCourses,adj, res) ) return {};
        else return res;
    }
};