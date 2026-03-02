#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        long long s, m;
        cin >> s >> m;

        vector<int> positions;
        int index = 0;
        long long temp = m;   // FIX: use long long and preserve m

        // Store set bit positions of m
        while (temp > 0)
        {
            if (temp & 1LL)
                positions.push_back(index);

            temp >>= 1;
            index++;
        }

        int i = positions.size() - 1;  // FIX: start from largest bit
        long long count = 0;

        while (i >= 0 && s > 0)
        {
            long long value = (1LL << positions[i]);  // FIX: avoid pow()

            if (value <= s)
            {
                s -= value;
                if()
                count++;
            }
            else
            {
                i--;
            }
        }

        if (s == 0)
            cout << count << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}