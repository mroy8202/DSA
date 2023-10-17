// LINK: https://leetcode.com/problems/combination-sum-ii/

class Solution {
private:
    void combinations(int ind, int target, vector<int>& candidates,
    vector<vector<int>>& ans, vector<int> ds) {
        // base case
        if(target == 0) {
            ans.push_back(ds);
            return ;
        } 

        for(int i = ind; i < candidates.size(); i++) {
            // avoid duplicates
            if(i > ind && candidates[i] == candidates[i-1]) continue;

            // when target exceeds
            if(candidates[i] > target) break;

            ds.push_back(candidates[i]);
            combinations(i+1, target-candidates[i], candidates, ans, ds);
            ds.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(0, target, candidates, ans, ds);
        return ans;
    }
};