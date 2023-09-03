#include<bits/stdc++.h>
using namespace std;

void subSequenceSumK(vector<int> arr, int i, int k, vector<int> ds, int sum) {
    // base case
    if(i == arr.size()) {
        if(sum == k) {
            for(auto it: ds) cout << it << " ";
            cout << endl;
        }
        return;
    }

    // exclude ith number
    subSequenceSumK(arr, i+1, k, ds, sum);

    // include ith number 
    sum += arr[i];
    ds.push_back(arr[i]);
    subSequenceSumK(arr, i+1, k, ds, sum);
    // ds.pop_back();
    // sum -= arr[i];
}

int main() {
    vector<int> arr = {5, 3, 6, 1, 8};
    int k = 11;
    vector<int> ds;
    subSequenceSumK(arr, 0, k, ds, 0);

    return 0;
}