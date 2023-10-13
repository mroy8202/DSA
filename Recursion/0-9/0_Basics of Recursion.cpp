#include<bits/stdc++.h>
using namespace std;

// TC: O(n). SC: O(n) whiich is stack space
void printName(int i, int n) {
    // base case
    if(i > n) return ;

    cout << "Mritunjay" << "\n";
    printName(i+1, n);
}

// TC: O(N). SC: O(N)
void print1ToN(int i, int n) {
    // base case
    if(i > n) return ;

    cout << i << "\n";
    print1ToN(i+1, n);
}

// TC: O(N). SC: O(N)
void printNto1(int i, int n) {
    // base case
    if(i < 1) return ;

    cout << i << "\n";
    printNto1(i-1, n); 
}

// TC: O(N). SC: O(N)
void backtrack_1toN(int i, int n) {
    if(i < 1) return ;

    backtrack_1toN(i-1, n);
    cout << i << "\n";
}

// TC: O(N). SC: O(N)
void backtrack_Nto1(int i, int n) {
    // base case
    if(i > n) return ;

    backtrack_Nto1(i+1, n);
    cout << i << "\n";
}

 
int main() {
    int n;
    cin >> n;

    // Question: Print name n times
    printName(1, n);

    // Question: Print Linearly from 1 to n
    print1ToN(1, n);

    // Question: Print Linearly from n to 1
    printNto1(n, n);

    // Question: Print 1 to n using BackTracking
    backtrack_1toN(n, n);

    // Question: Print n to 1 using BackTracking
    backtrack_Nto1(1, n);

    return 0;
}