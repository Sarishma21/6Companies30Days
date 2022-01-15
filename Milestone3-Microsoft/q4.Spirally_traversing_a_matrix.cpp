class Solution {   
    public: 
    vector<int> spirallyTraverse(vector<vector<int> > M, int r, int c) {
        int limit = r*c;
        vector<int> ans(limit);
        
        int x = 0, y = 0, dx = 1, dy = 0, boundary = 0;
        int index = 0;
        
        while(index < limit) {
            ans[index++] = M[y][x];

            if(dx == 1 && x == c - boundary - 1) {
                dx = 0;
                dy = 1;
            }

            if(dy == 1 && y == r - boundary - 1) {
                dx = -1;
                dy = 0;
            }

            if(dx == -1 && x == boundary) {
                dx = 0;
                dy = -1;
            }

            if(dy == -1 && y == boundary + 1) {
                dx = 1;
                dy = 0;
                ++boundary;
            }

            x += dx;
            y += dy;
        }
        return ans;
    }
};