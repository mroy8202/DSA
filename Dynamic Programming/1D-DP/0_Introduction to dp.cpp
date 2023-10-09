/* TRICK TO SOLVE A RECURSION PROBLEM
    1. Try to represent the problem in terms of indexes.
    2. Try all possible choices / ways at every index according to the problem statement.
    3. If the question states - 
        * Count all the ways - return sum of all choices / ways.
        * Find maximum / minimum - return the choices/way with maximum/minimum output.
*/

// LINK: https://leetcode.com/problems/fibonacci-number/description/
// NOTES: https://takeuforward.org/data-structure/dynamic-programming-introduction/

// Memoization | Top-Down Approach (we are going from n to the base case)
// TC: O(n)
// SC: O(n) + O(n) = O(n)
#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp) {
    // base case
    if(n <= 1) return n;

    // if value is already calculated, return the value
    if(dp[n] != -1) return dp[n];

    // call recursively to find the value and store in the dp vector
    else return dp[n] = fib(n-1, dp) + fib(n-2, dp); 
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    int ans = fib(n, dp);
    cout << ans << endl;

    return 0;
}

// Tabulation | Bottom-Up Approach (We are going from base case to n)
// TC: O(n)
// SC: O(n)
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);

    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << dp[n] << endl;

    return 0;
}

// Optimised Tabulation method
// TC: O(n)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int prev2 = 0;
    int prev1 = 1;
    for(int i = 2; i <= n; i++) {
        int curr_i = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr_i;
    }

    cout << prev1 << endl;

    return 0;
}