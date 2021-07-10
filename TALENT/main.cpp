#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define pip pair<int, pii >
#define fr first
#define sc second
#define camnguyenmeow ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define PROBLEMS            ""
/*   /\_/\
    (= ._.)
    / >?  \>$
*/
const int MAXN = 100003;
pip a[MAXN];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    int n, m, p, lwb;
    ll s1, s2; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i].fr;
    for (int i = 1; i <= n; ++i) cin >> a[i].sc.fr;
    sort(&a[1], &a[n+1]);
    for (int i = 1; i <= n; ++i) {
        a[i].sc.sc = a[i-1].sc.sc + a[i].fr*a[i].sc.fr;
        a[i].sc.fr += a[i-1].sc.fr;
    }
    pii zero = {0, 0};
    while (m--) {
        cin >> p;
        lwb = lower_bound(&a[1], &a[n+1], make_pair(p, zero)) - &a[0];
        s1 = p*a[lwb-1].sc.fr - a[lwb-1].sc.sc;
        if (a[lwb].fr == p) ++lwb;
        if (lwb <= n) s2 = a[n].sc.sc - a[lwb-1].sc.sc - p*(a[n].sc.fr - a[lwb-1].sc.fr);
        else s2 = 0;
        cout << s1 + s2 <<'\n';
    }
    return 0;
}
