/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int map[10] = {0};

        return dfs(root, map);
    }
private:
    int dfs(TreeNode *root, int *map){
        if(root->left == NULL && root->right == NULL){
            map[root->val]++;
            bool IsPalindrome = false;
            int countNodes = 0, numOdd = 0;

            for(int i = 1; i < 10; i++){
                if(map[i] > 0){
                    countNodes += map[i];
                    numOdd += (map[i]&1); 
                }
            }
            map[root->val]--;
            return (countNodes&1)?(numOdd == 1):(countNodes > 0 && numOdd == 0);
        }
        else{
            map[root->val]++;
            
            int count = 0;
            
            if(root->left != NULL) count += dfs(root->left, map);
            
            if(root->right != NULL) count += dfs(root->right, map);

            map[root->val]--;

            return count;
        }
    }
};
