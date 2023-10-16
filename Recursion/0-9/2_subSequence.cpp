#include<bits/stdc++.h>
using namespace std;

void subSequence(string s, int i, string output, vector<string>& ans) {
    // base case
    if(i >= s.length()) {
        ans.push_back(output);
        return;
    }

    // include ith character 
    output += s[i];
    subSequence(s, i+1, output, ans);
    output.pop_back();

    // exclude ith character
    subSequence(s, i+1, output, ans);
}

int main() {
    string s = "ab";
    vector<string> ans;
    subSequence(s, 0, "", ans);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}