//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool backtrack(vector<vector<char>>& board, int row, int col, string& word, int index) {
    // Base case: If all characters of the word are found
    if (index == word.length()) {
        return true;
    }

    int rows = board.size();
    int cols = board[0].size();

    // Check if the current cell is valid and matches the current character of the word
    if (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == word[index]) {
        char temp = board[row][col];
        board[row][col] = '#';  // Mark the current cell as visited

        // Recursively check the adjacent cells
        bool found = backtrack(board, row - 1, col, word, index + 1) ||  // Up
                     backtrack(board, row + 1, col, word, index + 1) ||  // Down
                     backtrack(board, row, col - 1, word, index + 1) ||  // Left
                     backtrack(board, row, col + 1, word, index + 1);    // Right

        board[row][col] = temp;  // Restore the current cell

        return found;
    }

    return false;
}
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
         int rows = board.size();
    int cols = board[0].size();

    // Iterate over each cell on the board
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (board[row][col] == word[0] && backtrack(board, row, col, word, 0)) {
                return true;  // Found the word
            }
        }
    }

    return false;
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends