//Pacific Atlantic Water Flow

class Solution {
public:
    
        bool isValid(int row , int col , int x, int y)
         { 
            if(x<0||x>=row || y<0||y>=col)return false;
            return true;
        }
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x ,int y){
        int row = heights.size();
        int col = heights[0].size();
        
        visited[x][y] = true; 
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        for(int i = 0 ; i < 4; i++){ 
            if(isValid(row, col , x + dx[i] ,  y + dy[i]) && 
               !visited[x + dx[i]][y+dy[i]] && 
               heights[x][y]<=heights[x + dx[i]][y + dy[i]])
            {
                dfs(heights, visited, x + dx[i], y + dy[i]);
            }
        }
        
    } 
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res; 
        
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<bool>> Pacific(row , vector<bool>(col, false));
        vector<vector<bool>> Atlantic(row , vector<bool>(col, false));
        
        for(int i = 0 ; i < row ; i++){
            dfs(heights, Pacific, i , 0);
            dfs(heights, Atlantic, i , col-1);
        }
        
        for(int i = 0 ; i < col ; i++){
            dfs(heights, Pacific, 0 , i);
            dfs(heights, Atlantic, row-1 , i);
        }
        
        for(int i = 0; i < row ; i++){
            for(int j = 0; j < col ; j++){
                if(Pacific[i][j] && Atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        
       return res; 
        
    }
};