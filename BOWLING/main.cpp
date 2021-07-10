#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef pair<int,int> pii;
const int MAXN = 1000001;
pii f[MAXN];
int n, a[MAXN];
int query(int l, int r) {
    if (r == l) return 0;
    pii ans = {0, INT_MAX};
    while (r >= l) {
        if (r - (r & -r) >= l) {
            ans = {max(ans.fr, f[r].fr), min(ans.sc, f[r].sc)};
            r -= r & (-r);
        } else {
            ans = {max(ans.fr, a[r]), min(ans.sc, a[r])};
            --r;
        }
    }
    return ans.fr - ans.sc;
}
void update(int i, int val) {
    while (i <= n) {
        f[i] = {max(f[i].fr, val), min(f[i].sc, val)};
        i += i & (-i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int k; cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        f[i].sc = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; update(i, a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int l = max(1, i-k), r = min(n, i+k);
        int tmp = query(l, r);
        ans = max(ans, tmp);
    }
    cout << ans;
}
