class Solution {
public:

    bool vertical(vector<vector<char>>& board, int n , int m){
        for(int i = 0 ; i < n ; i++)
        {
            unordered_set<char> x;
                for(int j = 0 ; j < m ; j++){
                    if(board[j][i]!='.'){
                        if(x.find(board[j][i]) != x.end()){
                            return false;
                        }
                        x.insert(board[j][i]);
                }
                
            }
        }
        return true;
    }


    bool horizontal(vector<vector<char>>& board, int n , int m){
        for(int i = 0 ; i < n ; i++)
        {
            unordered_set<char> x;
            for(int j = 0 ; j < m ; j++){
                if(board[i][j]!='.'){
                    if(x.find(board[i][j]) != x.end()){
                        return false;
                    }
                    x.insert(board[i][j]);
                }
            }
        }
        return true;
    }

bool grid(vector<vector<char>>& board, int n , int m){
    for(int i = 0 ; i < n ; i += 3)
    {
        for(int j = 0 ; j < m ; j += 3)
        {
            unordered_set<char> r;
            for(int x = i; x < i+3; x++)
            {
                for(int y = j; y < j+3; y++)
                {
                    if(board[x][y] != '.'){
                        if(r.find(board[x][y]) != r.end()){
                            return false;
                        }
                        r.insert(board[x][y]);
                    }
                }
            }
        }
    }
    return true;
}

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board.size();
        return horizontal(board,n,m) && vertical(board,n,m) && grid(board,n,m);
    }
};
