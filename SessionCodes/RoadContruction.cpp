#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int parent[N], sz[N];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b, int &maxSize) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        maxSize = max(maxSize, sz[a]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    int components = n;
    int maxSize = 1;

    while (m--) {
        int a, b;
        cin >> a >> b;

        if (find(a) != find(b)) {
            unite(a, b, maxSize);
            components--;
        }

        cout << components << " " << maxSize << "\n";
    }

    return 0;
}