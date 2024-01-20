class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> paths;
        
        dfs(0, 0, n, m, "", paths);
        
        return paths;
    }
    
    private:
    
    void dfs(int i, int j, const int n, vector<vector<int>> &m, string path, vector<string> &paths){
        if(i>=0 && i<n && j>=0 && j<n && m[i][j] == 1){
            if((i==(n-1)) && (j==(n-1)))
                paths.push_back(path);
            else{
                
                m[i][j] = 0;
                
                int dir[4][2] = {
                    {0,1},
                    {0,-1},
                    {-1, 0},
                    {1,0}
                };
                char p[4] = {'R', 'L', 'U', 'D'};
                
                for(int k = 0; k <4; k++){
                    path += p[k];
                    dfs(i + dir[k][0], j + dir[k][1], n, m, path, paths);
                    path.pop_back();
                }
                
                m[i][j] = 1;
            }
        }
        else return;
    }
};
