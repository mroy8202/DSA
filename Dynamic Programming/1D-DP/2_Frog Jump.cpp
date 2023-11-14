// LINK: https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
// NOTES: https://takeuforward.org/data-structure/dynamic-programming-frog-jump-dp-3/

// Memoization
// TC: O(n)
// SC: O(n) + O(n)
int solve(int ind, vector<int>& heights, vector<int>& dp) {
    // base case
    if(ind <= 0) {
        return 0;
    }

    if(dp[ind] != -1) return dp[ind];

    int oneStep = solve(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    int twoStep = INT_MAX;
    if(ind > 1) {
        twoStep = solve(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    } 

    return dp[ind] = min(oneStep, twoStep);
}

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n+1, -1);
    return solve(n-1, heights, dp);
}

// Tabulation
// TC: O(n)
// SC: O(n)
int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n, -1);
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        int oneStep = dp[i-1] + abs(heights[i] - heights[i-1]);
        int twoStep = INT_MAX;
        if(i > 1) {
            twoStep = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(oneStep, twoStep);
    }
    return dp[n-1];
}

// Space Optimisation
// TC: O(n)
// SC: O(1)
int frogJump(int n, vector<int> &heights) {
    int prev1 = 0, prev2 = 0, curr = 0;
    for(int i = 1; i < n; i++) {
        int fs = prev1 + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1) {
            ss = prev2 + abs(heights[i] - heights[i-2]);
        }
        curr = min(fs, ss);

        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}