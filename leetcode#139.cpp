class Trie{
private:
Trie* child[26];
bool isEnd;
public:
    Trie(){
        this->isEnd = false;
        fill(child, child + 26, (Trie*) NULL);
    }

    void insert(string str){
        Trie* start = this;
        for(char c: str){
            if(start->child[c - 'a'] != (Trie*) NULL){
                start = start->child[c-'a'];
            }
            else{
                start->child[c-'a'] = new Trie();
                start = start->child[c-'a'];
            }
        }
        start->isEnd = true;
    }

    bool search(string str){
        Trie* start = this;

        for(char c: str){
            if(start->child[c-'a'] == (Trie*) NULL) return false;
            else start = start->child[c-'a'];
        }

        return start->isEnd;
    }

};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* trie = new Trie();

        int size = wordDict.size(), n = s.length();
        vector<int> t(n + 1, -1);

        for(string str: wordDict){
            trie->insert(str);
        }

        return dfs(0, n, s, trie, t);
    }

private:
bool dfs(int start, int n, const string &s, Trie* trie, vector<int> &t){
    if(start == n) return true;
    else if(t[start] > -1) return t[start];
    else{
        string str;
        for(int i = start; i < n; i++){
            str += s[i];
            if(trie->search(str) && dfs(i + 1, n, s, trie, t)) return t[start] = true;
        }
        return t[start] = false;
    }
}
};
