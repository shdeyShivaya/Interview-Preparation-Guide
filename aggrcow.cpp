#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int binSearch(int n, int c, const vector<int> &stalls){
		int start = 1, end = stalls[n - 1] - stalls[0];
		int idealDistance = end;

		while(start <= end){
			int mid = start + (end - start) / 2;
			
			int k = numStallAtDistance(mid, n, stalls);
			
			if(k >= c){
				start = mid + 1;
				idealDistance = mid;
			}
			else end = mid - 1;
		}

		return idealDistance;
	}

private:
	int numStallAtDistance(int distance, int n, const vector<int> &stalls){
		int numStalls = 1;

		for(int i = 1, prev = stalls[0]; i < n; i++){
			if((stalls[i] - prev) >= distance){
				numStalls++;
				prev = stalls[i];
			}
		}

		return numStalls;
	}
};


int main(){
	int cases = 0;
	cin >> cases;

	while(cases--){
		int n, c;
		
		cin >> n >> c;

		vector<int> stalls(n);

		for(int i = 0; i < n; i++) cin >> stalls[i];
		
		sort(stalls.begin(), stalls.end());
		Solution solve = Solution();

		cout << solve.binSearch(n, c, stalls) << endl;
	}
	return 0;
}
