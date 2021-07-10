#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
#define camnguyenmeow ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define PROBLEMS            ""
/*   /\_/\
    (= ._.)
    / >?  \>$
*/
int info[4000005], a[1000005];
void build(int x, int l, int r) {
    if (l == r) {
        info[x] = a[l]; return;
    }
    int mid = (l+r)/2;
    build(2*x, l, mid); build(2*x+1, mid+1, r);
    info[x] = max(info[2*x], info[2*x+1]);
}
void update(int x, int l, int r, int i, int val) {
    if (l > i || r < i) return;
    if (l == r && l == i) {
        info[x] = val; return;
    }
    int mid = (l+r)/2;
    update(2*x, l, mid, i, val); update(2*x+1, mid+1, r, i, val);
    info[x] = max(info[2*x], info[2*x+1]);
}
int query(int x, int l, int r, int i, int j) {
    if (r < i || l > j) return INT_MIN;
    if (i <= l && j >= r) return info[x];
    int mid = (l+r)/2;
    int s1 = query(2*x, l, mid, i, j), s2 = query(2*x+1, mid+1, r, i, j);
    return max(s1, s2);
}
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    int n, m, x, y, z;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        cin >> x >> y >> z;
        if (x == 1) update(1, 1, n, y, z);
        else cout << query(1, 1, n, y, z) <<' ';
    }
    return 0;
}
