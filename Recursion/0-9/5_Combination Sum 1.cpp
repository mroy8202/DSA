// LINK: https://leetcode.com/problems/combination-sum/

class Solution {
private:
    void combinations(int ind, int target, vector<int> ds, vector<vector<int>>& ans, vector<int>& candidates) {
        // base case
        if(ind >= candidates.size()) {
            if(target == 0) ans.push_back(ds);
            return ;
        }

        // pick element
        if(candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            combinations(ind, target-candidates[ind], ds, ans, candidates);
            ds.pop_back();
        }

        // donot pick element
        combinations(ind+1, target, ds, ans, candidates);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(0, target, ds, ans, candidates);
        return ans;
    }
};