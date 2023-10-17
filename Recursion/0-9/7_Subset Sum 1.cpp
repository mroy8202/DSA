// LINK: https://practice.geeksforgeeks.org/problems/subset-sums2234/1

// TC: O(2^n * logn)
class Solution {
private:    
    void subSum(int ind, int sum, vector<int>& arr, vector<int>& ans, int N) {
        // base case
        if(ind >= N) {
            ans.push_back(sum);
            return ;
        }

        // pick the element 
        subSum(ind+1, sum + arr[ind], arr, ans, N);

        // donot pick the element 
        subSum(ind+1, sum, arr, ans, N);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N) {
        int sum = 0;
        vector<int> ans;
        subSum(0, sum, arr, ans, N);
        sort(ans.begin(), ans.end());
        return ans;
    }
};