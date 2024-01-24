class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();

        int map1[128] = {0}, count = 0, minWindow = m + 1, optimizedStart= 0;

        for(char c:t){
            if(map1[c]++ == 0) count++;
        }

        for(int start = 0, end = 0, k = 0, map2[128] = {0}; end < m; end++){
            if((++map2[s[end]] == map1[s[end]]) && (map1[s[end]] > 0)){
                k++;
            }

            while(k >= count && start <= end){
                if(minWindow >= (end - start + 1)){
                    optimizedStart = start;
                    minWindow = end - start + 1;
                }

                if((map1[s[start]] > 0) && (map1[s[start]] == map2[s[start]])){
                    k--;
                }
                map2[s[start]]--;
                start++;
            }
        }
        cout << minWindow;
        return (minWindow < m + 1)? s.substr(optimizedStart, minWindow): "";
    }
};
