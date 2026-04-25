#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    struct Node {
        long long sum;
        int mx;
        int mn;
    };

    int n;
    vector<Node> tree;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    Node merge(Node left, Node right) {
        Node res;
        res.sum = left.sum + right.sum;
        res.mx = max(left.mx, right.mx);
        res.mn = min(left.mn, right.mn);
        return res;
    }

    void build(int node, int start, int end, vector<int>& arr) {
        if (start == end) {
            tree[node] = {arr[start], arr[start], arr[start]};
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node + 1, start, mid, arr);
        build(2 * node + 2, mid + 1, end, arr);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return {0, INT_MIN, INT_MAX};
        }

        if (l <= start && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;

        Node left = query(2 * node + 1, start, mid, l, r);
        Node right = query(2 * node + 2, mid + 1, end, l, r);

        return merge(left, right);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = {val, val, val};
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node + 1, start, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, end, idx, val);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree st(arr);

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r; 
            auto ans = st.query(0, 0, n - 1, l, r);

            cout << "Sum = " << ans.sum << endl;
            cout << "Max = " << ans.mx << endl;
            cout << "Min = " << ans.mn << endl;
        }
        else if (type == 2) {
            int idx, val;
            cin >> idx >> val;
            st.update(0, 0, n - 1, idx, val);
        }
    }

    return 0;
}