class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size(); // Size of board
        int dx[] = {-1,-1,-1,0,0,1,1,1}; 
        int dy[] = {-1,0,1,-1,1,-1,0,1}; /*Direction vectors to visit  8 neighbours */
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){ // For each cell of the board
                int countLive = 0; // Count how many live neighbours it has
                for(int k = 0; k < 8 ; k++){ // visit its 8 neighbours
                    int destx = i + dx[k];
                    int desty = j + dy[k]; // current neighbour is destx and desty
                    if(destx < 0 || desty < 0 || destx >= n || desty >= m) continue; // neighbour should be within boundary of the board
                    if(board[destx][desty] == 1 || board[destx][desty] == 2) countLive++; // 1 or 2 means it was alive in previous state
                } 
                if((countLive < 2 || countLive > 3) && board[i][j] == 1) board[i][j] = 2; //conditions for a live cell to die
                if(board[i][j] == 0 && countLive == 3) board[i][j] = 3; // conditions for a dead cell to come alive
            }
        }
        for(int i = 0 ; i < n;  i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 2) board[i][j] = 0;
                if(board[i][j] == 3) board[i][j] = 1;
                // mark each newly alive and dead cell as 0 and 1.
            }
        }
    }
};