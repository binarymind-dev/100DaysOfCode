#include <iostream>
#include <vector>
using namespace std;

int prefixSum(vector<int>& arr, int l, int r) {
    vector<int> prefix(arr.size() + 1, 0);

    for (int i = 0; i < arr.size(); i++)
        prefix[i+1] = prefix[i] + arr[i];

    return prefix[r+1] - prefix[l];
}