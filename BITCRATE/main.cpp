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
struct dev{int s1, s2, id;} a[300005];
int info[400002], ans[300005];
int query(int x, int l, int r, int i) {
    if (l > i) return 0;
    if (r <= i) return info[x];
    int mid = (l+r)/2;
    int s1 = query(2*x, l, mid, i),
        s2 = query(2*x+1, mid+1, r, i);
    return s1+s2;
}
void update(int x, int l, int r, int i) {
    if (l > i || r < i) return;
    if (l == i && r == i) {
        info[x] ++;
        return;
    }
    int mid = (l+r)/2;
    update(2*x, l, mid, i);
    update(2*x+1, mid+1, r, i);
    info[x] = info[2*x] + info[2*x+1];
}
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    int n, maxs2 = 0; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].s1 >> a[i].s2;
        a[i].id = i;
        maxs2 = max(maxs2, a[i].s2);
    }
    sort(&a[1], &a[n+1], [&] (dev x, dev y)
         {return (x.s1 < y.s1) || (x.s1 == y.s1 && x.s2 < y.s2);});
    ans[a[1].id] = 0;
    int pres1 = a[1].s1, pos = 1;
    vector<int> pres2;
    for (int z = 1; z <= n; ) {
        pres2 = {a[z].s2};
        ans[a[z].id] = query(1, 1, maxs2, a[z].s2);
        for (int i = z+1; i <= n; ++i) {
            if (a[i].s1 == a[z].s1) {
                for (int j : pres2)
                    if (j < a[i].s2) ++ans[a[i].id];
                pres2.push_back(a[i].s2);
                pos = i;
                int qr = query(1, 1, maxs2, a[i].s2);
                ans[a[i].id] += qr;
            } else break;
        }
        pos = max(pos, z);
        z = pos+1;
        for (int i : pres2)
            update(1, 1, maxs2, i);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] <<' ';
    return 0;
}
