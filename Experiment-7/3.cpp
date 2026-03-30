#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& pt) {
    int ans = 1;
    int n = pt.size();

    for (int i = 0; i < n - 1; i++) {
        map<double, int> mp;

        for (int j = i + 1; j < n; j++) {
            double slope;

            if (pt[j][0] == pt[i][0]) {
                slope = INT_MAX; // vertical line
            } else {
                slope = (double)(pt[j][1] - pt[i][1]) /
                        (pt[j][0] - pt[i][0]);
            }

            mp[slope]++;
        }

        int temp = 0;
        for (auto it : mp) {
            temp = max(temp, it.second);
        }

        ans = max(ans, temp + 1);
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    cout << "Enter points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    cout << "Maximum points on same line: " << maxPoints(points);

    return 0;
}