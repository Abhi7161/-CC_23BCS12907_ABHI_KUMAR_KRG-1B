#include <bits/stdc++.h>
using namespace std;

int triangularSum(vector<int>& nums) {
    while (nums.size() > 1) {
        vector<int> newNums;

        for (int i = 0; i < nums.size() - 1; i++) {
            newNums.push_back((nums[i] + nums[i + 1]) % 10);
        }

        nums = newNums;
    }

    return nums[0];
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = triangularSum(nums);

    cout << "Triangular Sum: " << result;

    return 0;
}