#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long mid, vector<pair<int, int>> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        auto it = arr[i];

        if (it.second > mid)
            return false;
        else
            mid -= it.first;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end(),
         [](auto &a, auto &b)
         {
             return (a.second - a.first) > (b.second - b.first);
         });
    long long start = 0;
    long long end = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        start = max(start, (long long)tasks[i].second);
        end += tasks[i].first;
    }
    end += start;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;

        if (isPossible(mid, tasks, n))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    cout << ans << endl;
}