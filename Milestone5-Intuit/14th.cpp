//As Far from Land as Possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0;j < col; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        
        if(q.size() == 0 || q.size() == grid.size()*grid[0].size()){
            return -1;
        }
        
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0,-1}};
        int res = -1,step=0;
        while(!q.empty()){
            step++;
            int len = q.size();
            
             for(int i = 0; i < len; i++){
                auto [x, y] = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    int tx = x + dir[j][0];
                    int ty = y + dir[j][1];
                    if(tx < 0 || ty < 0 || tx >= row || ty >= col || grid[tx][ty])
                        continue;
                    res = step;
                    grid[tx][ty] = 1;
                    q.push({tx, ty});
                }
            }
        }
        return res;
    }
};