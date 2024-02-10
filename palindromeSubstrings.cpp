class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();

        vector<vector<int>> t(n, vector<int>(n, -1));
        int count = 0;

        for(int size = 1; size <= n; size++){
            for(int i = 0; i + size - 1 < n; i++){
//                int isPalin = dfs(i, i + size - 1, s, t);
                if(size <= 1) t[i][i + size - 1] = 1;
                else if(size == 2) t[i][i + size - 1] = (s[i] == s[i + size - 1]);
                else{
                    if(s[i] == s[i + size - 1]) t[i][i + size - 1] = t[i + 1][i + size - 1 - 1];
                    else t[i][i + size - 1] = 0;
                }
                int isPalin = t[i][i + size - 1];
                if(isPalin) count++;
            }
        }
        return count;
    }
private:
    int dfs(int start, int end, string s, vector<vector<int>> &t){
        if(start >= end) return 1;
        else if(t[start][end] != -1) return t[start][end];
        else if(end - start + 1 == 2) return t[start][end] = (s[start] == s[end]);
        else{
            if(s[start] == s[end]) return t[start][end] = dfs(start + 1, end - 1, s, t);
            else return t[start][end] = 0;
        }
    }
};

/*
0 a a a
a 1 0 0
a 0 1 0
a 0 0 1
*/
