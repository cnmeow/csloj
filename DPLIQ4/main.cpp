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
int f[100005];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    memset(f, 0x3f, sizeof(f));
    int n, a, ans = 1; cin >> n >> a;
    f[1] = a;
    for (int i = 1; i < n; ++i) {
        cin >> a;
        int lwb = lower_bound(&f[1], &f[ans+1], a) - &f[0];
        f[lwb] = a;
        ans = max(ans, lwb);
    }
    cout << ans;
}
