#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long gcd(long long x, long long y)
    {
        while(y)
        {
            long long temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }

    int nthMagicalNumber(int n, int a, int b)
    {
        long long l = min(a, b);
        long long r = 1LL * n * min(a, b);

        long long lcm = (1LL * a * b) / gcd(a, b);

        while(l < r)
        {
            long long mid = l + (r - l) / 2;

            long long count =
                mid / a +
                mid / b -
                mid / lcm;

            if(count < n)
                l = mid + 1;
            else
                r = mid;
        }

        return l % MOD;
    }
};

int main()
{
    Solution obj;

    cout << obj.nthMagicalNumber(4, 2, 3);

    return 0;
}