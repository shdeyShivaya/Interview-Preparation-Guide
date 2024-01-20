class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();

        if(m > 0){
            int n = board[m - 1].size(), x = word.length();

            vector<vector<int>> visited(m, vector<int>(n, 0));

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(dfs(i, j, m, n, 0, board, word, visited)) return true;
                }
            }
            return false;
        }
        else return false;
    }

private:
bool dfs(int i, int j, int m, int n, int x, const vector<vector<char>> &board, const string &word, vector<vector<int>> &visited){
    if(x >= word.length()) return true;
    else if(i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 0 && board[i][j] == word[x]){
        bool result = false;

        int dir[4][2] = {
            {0, 1},
            {0, -1},
            {-1, 0},
            {1, 0}
        };
        visited[i][j] = 1;

        for(int k = 0; k < 4; k++){
            result = result || dfs(i + dir[k][0], j + dir[k][1], m, n, x + 1, board, word, visited);
        }

        visited[i][j] = 0;

        return result;
    }
    else return false;
}
};
