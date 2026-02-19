#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int nthMagicalNumber(int n, int a, int b) {
    const long long MOD = 1'000'000'007;

    long long A = a;
    long long B = b;
    long long L = lcm(A, B);

    long long lo = min(A, B) - 1;
    long long hi = 1LL * min(A, B) * n + 1;

    while (hi - lo > 1) {
        long long mid = lo + (hi - lo) / 2;
        long long count = mid / A + mid / B - mid / L;

        if (count >= n)
            hi = mid;
        else
            lo = mid;
    }

    return hi % MOD;
}

int main() {
    int n, a, b;
    cout << "Enter n, a, b: ";
    cin >> n >> a >> b;

    cout << nthMagicalNumber(n, a, b) << endl;

    return 0;
}
