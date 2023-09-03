/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input:
              5
            /   \
          4      6
         /        \
        3          7
                    \
                     8
n1 = 7, n2 = 8
Output: 7

Example 2:
Input:
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2

Constraints:
The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.
*/

// iterative solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        while(root) {
            // p & q lies in left subtree
            if( (p->val < root->val) && (q->val < root->val) ) {
                root = root->left;
            }

            // p & q lies in right subtree
            else if( (p->val > root->val) && (q->val > root->val) ) {
                root = root->right;
            }

            // p & q lies in different subtrees or one of p & q is found
            else {
                return root;
            }
        }
        return ans;
    }
};
// TC: O(H)
// SC: O(1)

// Recursive Solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // p & q lies in left subtree
        if( (p->val < root->val) && (q->val < root->val) ) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // p & q lies in right subtree
        else if( (p->val > root->val) && (q->val > root->val) ) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // p & q lies in different subtrees or one of p & q is found
        return root;
    }
};
// TC: O(H)
// SC: O(1), auxiliary space is O(H)