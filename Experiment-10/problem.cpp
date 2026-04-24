#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> tree;

    void update(int index, int n) {
        while (index <= n) {
            tree[index] += 1;
            index += index & (-index);
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        int n = sorted.size();
        tree.assign(n + 1, 0);

        vector<int> result(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            int rank = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
            result[i] = query(rank - 1);
            update(rank, n);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5, 2, 6, 1};
    vector<int> ans = sol.countSmaller(nums);

    for (int x : ans)
        cout << x << " ";

    return 0;
}