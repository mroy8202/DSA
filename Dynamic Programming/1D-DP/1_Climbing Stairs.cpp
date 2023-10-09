// LINK: https://leetcode.com/problems/climbing-stairs/description/
// NOTES: https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/

// Recursion + Memoization
// TC: O(n)
// SC: O(n) + O(n)
class Solution {
private: 
    int ways(int n, vector<int>& dp) {
        // base case
        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];
        return dp[n] = ways(n-1, dp) + ways(n-2, dp);
    }
    
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return ways(n, dp);
    }
};

// Tabulation Method
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// Tabulation Method
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int climbStairs(int n) {
        int stair0 = 1;
        int stair1 = 1;
        for(int i = 2; i <= n; i++) {
            int ithStair = stair1 + stair0;
            stair0 = stair1;
            stair1 = ithStair;
        }
        return stair1;
    }
};
