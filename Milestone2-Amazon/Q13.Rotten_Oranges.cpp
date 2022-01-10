#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
         int M = grid.size();
        int N = grid[0].size();
        
        vector<pair<int, int>> initially_fresh;
        queue<pair<int, int>> decay_queue;
        
        vector<vector<bool>> queued(M, vector<bool>(N, false));
        
        
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(grid[i][j] == 1) {
                    initially_fresh.push_back({i, j});
                }
                else if(grid[i][j] == 2) {
                    decay_queue.push({i, j});
                }
            }
        }
        decay_queue.push({-1, -1});
        
        int sec = -1;

        while(!decay_queue.empty()) {
            pair<int, int> pos = decay_queue.front();
            decay_queue.pop();

            int y = pos.first;
            int x = pos.second;

            if(x == -1 && y == -1) {
                ++sec;
                if(!decay_queue.empty()) {
                    decay_queue.push({-1, -1});
                }
                continue;
            }

            // left
            if(x > 0 && !queued[y][x-1] && grid[y][x-1] == 1) {
                queued[y][x-1] = true;
                decay_queue.push({y, x-1});
            }

            // right
            if(x < N - 1 && !queued[y][x+1] && grid[y][x+1] == 1) {
                queued[y][x+1] = true;
                decay_queue.push({y, x+1});
            }

            // top
            if(y > 0 && !queued[y-1][x] && grid[y-1][x] == 1) {
                queued[y-1][x] = true;
                decay_queue.push({y-1, x});
            }

            // bottom
            if(y < M - 1 && !queued[y+1][x] && grid[y+1][x] == 1) {
                queued[y+1][x] = true;
                decay_queue.push({y+1, x});
            }
        }
        
        for(auto pos: initially_fresh) {
            if(!queued[pos.first][pos.second]) {
                return -1;
            }
        }
        
        return sec;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}