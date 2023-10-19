// LINK: https://leetcode.com/problems/subsets-ii/description/
// NOTES: https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/

class Solution {
private:
    void findSubset(int ind, vector<int> ds, vector<vector<int>>& ans, vector<int>& nums) {
        ans.push_back(ds);
        for(int i = ind; i < nums.size(); i++) {
            // take 1st element and then avoid duplicate elements
            if(i != ind && nums[i] == nums[i-1]) continue;
            
            ds.push_back(nums[i]);
            findSubset(i+1, ds, ans, nums);
            ds.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findSubset(0, ds, ans, nums);
        return ans;
    }
};