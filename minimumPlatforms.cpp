class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    	vector<pair<int, int>> startings;
    	for(int i = 0; i < n; i++) startings.push_back({arr[i], i});
    	sort(startings.begin(), startings.end());
    	
    	priority_queue<int, vector<int>, greater<int>> minHeap;
    	int start = 0, end = 0;
    	int minPlatforms = 0;
    	
    	for(int i = 0; i < n; i++){
    	    while(!minHeap.empty() && startings[i].first > minHeap.top()){
    	        minHeap.pop();
    	    }
    	    minHeap.push(dep[startings[i].second]);
    	    
    	    minPlatforms = max(minPlatforms, (int)minHeap.size());
    	}
    	
    	return minPlatforms;
    }
};
