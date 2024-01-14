/*
1657. Determine if Two Strings Are Close
Solved
Medium
Topics
Companies
Hint
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int map1[26] = {0}, map2[26] = {0};

        int n1 = word1.length(), n2 = word2.length();

        if(n1 != n2) return false;
        else{
            for(int i = 0; i < n1; i++){
                map1[word1[i] - 'a']++;
                map2[word2[i] - 'a']++;
            }

            int bucket1[n1 + 1], bucket2[n1 + 1];
            memset(bucket1, 0, sizeof(bucket1));
            memset(bucket2, 0, sizeof(bucket2));

            for(int i = 0; i < 26; i++){
                if((map1[i] > 0 && map2[i] > 0) || map1[i] == 0 && map2[i] == 0){
                    if(map1[i] > 0 && map2[i] > 0){
                        bucket1[map1[i]]++;
                        bucket2[map2[i]]++;
                    }
                }
                else return false;
            }

            for(int i = 1; i <= n1; i++){
                if(bucket1[i] != bucket2[i]) return false;
            }

            return true;
        }
    }
};


int main(){

    Solution sol = Solution();
    
    cout << sol.closeStrings('cabbba', 'abbccc');

    return 0;
}