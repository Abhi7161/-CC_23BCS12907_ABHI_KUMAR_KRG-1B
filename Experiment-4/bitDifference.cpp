#include <iostream>
#include <vector>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n != 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int sumBitDiff(vector<int>& arr) {
    int diff = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i; j < arr.size(); j++) {
            int x = arr[i] ^ arr[j];
            int count = countSetBits(x);
            diff += 2 * count;
        }
    }

    return diff;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << sumBitDiff(arr) << endl;

    return 0;
}
