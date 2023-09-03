/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // ans vector to store answer
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        // use a queue (FIFO)
        queue<TreeNode*> q;
        // push root into queue
        q.push(root);

        while(!q.empty()) {
            //size
            int size = q.size();
            // level to store nodes at each level
            vector<int> level;

            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                level.push_back(temp->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

// Time Complexity: O(n) used by queue
// Space Complexity: O(n) used by queue