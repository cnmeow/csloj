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
ll a[100005];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(&a[1], &a[n+1]);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int upb = upper_bound(&a[i+1], &a[n+1], a[i]) - &a[0];
        if (a[upb] > a[i]) ans = max(ans, (n-upb+2)*a[i]); // k = a[i]
        ans = max(ans, (n-i+1)*(a[i]-1)); // k = a[i]-1
    }
    cout << ans;
    return 0;
}
