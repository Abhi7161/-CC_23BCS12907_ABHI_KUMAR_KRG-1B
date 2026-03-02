#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_set<string> memory;
    memory.reserve(n * 2);
    memory.max_load_factor(0.7);

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        memory.insert(s);
    }
    while (m--) {
        cin >> s;
        bool found = false;

        for (int i = 0; i < s.size() && !found; i++) {
            char original = s[i];
            for (char ch : {'a', 'b', 'c'}) {
                if (ch == original) continue;

                s[i] = ch;

                if (memory.find(s) != memory.end()) {
                    found = true;
                    break;
                }
            }

            s[i] = original; 
        }

        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}