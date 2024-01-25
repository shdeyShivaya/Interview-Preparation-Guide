class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        
        int m = str1.length(), n = str2.length();
        int minWindow = m + 1, optimizedStart = 0;
        
        for(int start = 0, end = 0; end < m; end++){
            
            while((start <= end) && isSubsequence(start, end, n, str1, str2)){
                
                if(minWindow > (end - start + 1)){
                    optimizedStart = start;
                    minWindow = min(minWindow, (end - start + 1));
                }
                start++;
            }
        }
        
        return (minWindow < m + 1)?str1.substr(optimizedStart, minWindow):"";
    }
private:
    bool isSubsequence(int start, int end, int n, const string &str1, const string &str2){
        if(n == 0) return true;
        else if((n > 0) && (end >= start)){
            if(str1[end] == str2[n - 1]) return isSubsequence(start, end - 1, n - 1, str1, str2);
            else return isSubsequence(start, end - 1, n, str1, str2);
        }
        else{
            return false;
        }
    }
};
