/*
0,0  2,3 -> 1,1  target < matrix[mid] -> end = (x,y) yE[0, n - 1], xE[0,mid_x]

0,0  1,1


pos = f(x,y)
start_pos
end_pos
x, y = f1(mid_pos)

strt = 0
end = m * n - 1
mid = (m*n - 1) / 2 = mid_pos

x = pos / n
y = pos % n


10 14
11 15
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();

        if(m == 0) return false;
        else{
            int n = matrix[m - 1].size();
            
            int start = 0, end = (m * n) - 1, mid;
            
            while(start < end){
                mid = start + (end - start) / 2;

                int x_mid = mid / n, y_mid = mid % n;
                int k = matrix[x_mid][y_mid];
                if(k < target) start = mid + 1;
                else end = mid;
            }
            
            if(start >= 0 && start < m*n){
                int x_target = start / n;
                int y_target = start % n;

                return  matrix[x_target][y_target] == target;
            }
            else return false;
        }
    }
};