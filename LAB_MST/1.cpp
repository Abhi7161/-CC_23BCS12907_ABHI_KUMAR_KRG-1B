#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid, vector<pair<int, int>> &arr, int n)
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
             return a.second < b.second;
         });
    int start = INT_MAX;
    int end = 0;
    int ans = 0;
for(int i=0;i<n;i++)
{
    auto it=tasks[i];
    cout<<it.first<<" "<<it.second<<" ";
}
cout<<endl;
    for (int i = 0; i < n; i++)
        start = min(start, tasks[i].second);

    for (int i = 0; i < n; i++)
        end += tasks[i].second;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

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