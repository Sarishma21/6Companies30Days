// Word Search

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool dfs(vector<vector<char>>&board,int i, int j, int count,string word){
        
       
        int n = word.length();
        int row = board.size();
        int col = board[0].size();
        if(count == n)
        return true;
        
        if(i < 0 || j < 0 || i >= row || j >= col || board[i][j] != word[count])
        return false;
        
        char ch = board[i][j];
        board[i][j] = ' ';
        
        bool check = dfs(board, i+1,j,count+1,word) || dfs(board, i-1,j,count+1,word)|| dfs(board, i, j+1,count+1,word) || dfs(board,i,j-1,count+1,word);
        
        board[i][j] = ch;
        return check;
        
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                
                if(board[i][j] == word[0] && dfs(board, i, j,0,word))
                return true;
            }
        }
      return false;  
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends