class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return false;
        else{
            int n = grid[m - 1].size();
            int island_max_size = 0;
            vector<vector<int>> visited(m, vector<int>(n, 0));

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 1 && !visited[i][j]){
                        int island_size = bfs(i, j, m, n, grid, visited);
                        island_max_size = max(island_max_size, island_size);
                    }
                }
            }
            return island_max_size;
        }
    }

private:
int bfs(int i, int j, const int m, const int n, const vector<vector<int>> &grid, vector<vector<int>> &visited){
    if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1 && !visited[i][j]){
        //visited[i][j] = 1;
        
        int size = 0;

        int dir[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

       


        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()){
            int num = q.size();

            while(num--){
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !visited[x][y]){
                    size++;

                    visited[x][y] = 1;

                     for(int k = 0; k < 4; k++){
                         int x_n = x + dir[k][0], y_n = y + dir[k][1];

                        if(x_n >= 0 && x_n < m && y_n >= 0 && y_n < n && grid[x_n][y_n] == 1 && !visited[x_n][y_n]) q.push({x_n, y_n});
                    }
                }
            }
        }
        return size; 
    }
    else return 0;
}
};


int main(){
    Solution sol = Solution();

    sol.maxAreaOfIsland({{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}});
    return 0;
}