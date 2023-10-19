// LINK: https://leetcode.com/problems/permutations/description/
// NOTES: https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/

// Brute-Force Approach
// TC: O(n! * n)
// SC: O(n)
class Solution {
private:
    void findPermutation(vector<int>& nums, vector<bool> vis, 
    vector<int> ds, vector<vector<int>>& ans) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!vis[i]) {
                vis[i] = true;
                ds.push_back(nums[i]);
                findPermutation(nums, vis, ds, ans);
                vis[i] = false;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> vis(nums.size(), false);
        findPermutation(nums, vis, ds, ans);
        return ans;
    }
};

// Optimised Approach
// TC: O(n! * n)
// SC: O(1)
class Solution {
private:
    void findPermutation(int ind, vector<int>& nums, vector<vector<int>>& ans) {
        if(ind >= nums.size()) {
            ans.push_back(nums);
        }

        for(int i = ind; i < nums.size(); i++) {
            swap(nums[ind], nums[i]);
            findPermutation(ind+1, nums, ans);

            // backtrack
            swap(nums[ind], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermutation(0, nums, ans);
        return ans;
    }
};
