#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    long int n = 0;
    cin >> n;
    while(n--){
        int w = 0, h = 0, c = 0, x, y;
 
        vector<int> width;
        width.push_back(0);
 
        vector<int> height;
        height.push_back(0);
 
        cin >> w >> h >> c;
 
        while(c--){
            cin >> x >> y;
            width.push_back(x);
            height.push_back(y);
        }
 
        width.push_back(w + 1);
        height.push_back(h + 1);
 
        sort(width.begin(), width.end());
        sort(height.begin(), height.end());
 
        int max_cells_width = 0,
            max_cells_height = 0;
 
        for(int i = 1; i < width.size(); i++){
            max_cells_width = max(max_cells_width, width[i] - width[i - 1] - 1);
            max_cells_height = max(max_cells_height, height[i] - height[i - 1] - 1);
        }
 
        cout << (max_cells_width * max_cells_height) << endl;
    }
    return 0;
}