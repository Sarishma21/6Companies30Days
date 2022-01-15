class Solution {
    public:
    int calc_area(int r, int c, vector<vector<int>>& grid) {

        int R = grid.size() - 1;
        int C = grid[0].size() - 1;

        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;

        int area = 0;

        while(!q.empty()) {
            ++area;

            pair<int, int> block = q.front();
            r = block.first;
            c = block.second;

            // top
            if(r > 0 && grid[r-1][c] == 1) {
                q.push({r-1, c});
                grid[r-1][c] = 0;
            }

            // right
            if(c < C && grid[r][c+1] == 1) {
                q.push({r, c+1});
                grid[r][c+1] = 0;
            }

            // bottom
            if(r < R && grid[r+1][c] == 1) {
                q.push({r+1, c});
                grid[r+1][c] = 0;
            }

            // left
            if(c > 0 && grid[r][c-1] == 1) {
                q.push({r, c-1});
                grid[r][c-1] = 0;
            }

            // topright
            if(r > 0 && c < C && grid[r-1][c+1] == 1) {
                q.push({r-1, c+1});
                grid[r-1][c+1] = 0;
            }
    
            // bottomright
            if(r < R && c < C && grid[r+1][c+1] == 1) {
                q.push({r+1, c+1});
                grid[r+1][c+1] = 0;
            }

            // bottomleft
            if(r < R && c > 0 && grid[r+1][c-1] == 1) {
                q.push({r+1, c-1});
                grid[r+1][c-1] = 0;
            }

            // topleft
            if(r > 0 && c > 0 && grid[r-1][c-1] == 1) {
                q.push({r-1, c-1});
                grid[r-1][c-1] = 0;
            }

            q.pop();
        }

        return area;
    }

    int findMaxArea(vector<vector<int>>& grid) {
        int max_area = 0;
        queue<int> q;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < m; ++c) {
                if(grid[r][c]) {
                    max_area = max(max_area, calc_area(r, c, grid));
                }
            }
        }
        
        return max_area;
    }
};