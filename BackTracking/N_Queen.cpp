//Brute
class Solution {
public:
    bool isSafe1(int row, int col, vector<string> board, int n) 
    {
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        
        col = dupcol; 
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--; 
        }
    
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--; 
        }
        
        return true; 
    }
public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) 
    {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(isSafe1(row, col, board, n)) {
                board[row][col] = 'Q'; 
                solve(col+1, board, ans, n); 
                board[row][col] = '.'; 
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
         
        solve(0,board, ans, n); 
        return ans; 
    }
};

// OR
class Solution{
public:
    vector<vector<int>> ans;
	bool isSafe(int row, int col, vector<int> &path)
	{
		for (int i = row - 2; i >= 0; i--) 
		{
			if (path[i] == col)
				return false;
		}
		for (int i = row - 2; i >= 0; i--) 
		{
			if(path[i] == i - row + col + 1)
			return false;
		}
		for (int i = row - 2; i >= 0; i--) 
		{
			if(path[i] == row + col - i - 1)
			return false;
		}
		return true;
	}

	void helper(int row, int n, vector<int> path)
	{
		if (path.size() == n)
		{
			ans.push_back(path);
		}
		for (int col = 1; col <= n; col++)
		{
			if (isSafe(row, col, path))
			{
				path.push_back(col);
				helper(row + 1, n, path);
				path.pop_back();
			}
		}
	}

	vector<vector<int>> nQueen(int n)
	{
		if (n == 0 || n == 2 || n == 3)
			return ans; 
		if (n == 1)
			return {{1}};
		vector<int> path;
		helper(1, n, path);
		return ans;
	}
};

//Efficient
class Solution {

public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, 
               vector<int> &leftRow, 
               vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        
        for(int row = 0;row<n;row++) {
            if(leftRow[row]==0 && lowerDiagonal[row + col] == 0 
               && upperDiagonal[n-1 + col - row] == 0) {
                
                board[row][col] = 'Q'; 
                leftRow[row] = 1; 
                lowerDiagonal[row+col] = 1; 
                upperDiagonal[n-1 + col - row] = 1;
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
                board[row][col] = '.'; 
                leftRow[row] = 0; 
                lowerDiagonal[row+col] = 0; 
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); 
        solve(0,board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
        return ans; 
    }
    
};