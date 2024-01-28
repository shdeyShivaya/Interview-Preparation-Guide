class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        else{
            int n = matrix[m - 1].size();
            vector<int> t(n, 0);

            int area = 0;

            for(int i = 0; i < m; i++){
                vector<int> leftBoundary(n, -1), rightBoundary(n, n);

                stack<int> stk1, stk2;

                for(int j = 0; j < n; j++){
                    if(matrix[i][j] == '1') t[j] += 1;
                    else t[j] = 0;

                }

                for(int j = 0; j < n; j++){
                    while(!stk1.empty() && t[stk1.top()] >= t[j]){
                        stk1.pop();
                    }

                    if(stk1.empty()) leftBoundary[j] = -1;
                    else leftBoundary[j] = stk1.top();

                    stk1.push(j);
                }
                for(int j = n - 1; j >= 0; j--){
                    while(!stk2.empty() && t[stk2.top()] >= t[j]){
                        stk2.pop();
                    }
                    if(stk2.empty()) rightBoundary[j] = n;
                    else rightBoundary[j] = stk2.top();

                    stk2.push(j);
                }
                for(int j = 0; j < n; j++){
                    int size = min(t[j], ((rightBoundary[j] - 1) - (leftBoundary[j] + 1) + 1));
                    
                    area = max(area, size*size);
                }
            }
            return area;
        }
    }
};
