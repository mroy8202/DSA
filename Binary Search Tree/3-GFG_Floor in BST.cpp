/*
You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

Example:
Input:
n = 7               2
                     \
                      81
                    /     \
                 42       87
                   \       \
                    66      90
                   /
                 45
x = 87
Output:
87
Explanation:
87 is present in tree so floor will be 87.

Example 2:
Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 11
Output:
9

Constraint:
-109 <= Noda data <= 109
1 <= n <= 105

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/

int floor(Node* root, int x) {
    int ans = -1;
    while(root != NULL) {
        if(root->data == x) {
            return x;
        }
            
        else if(root->data > x) {
            // serach in left
            root = root->left;
        }
            
        else {
            // serach in right
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}
