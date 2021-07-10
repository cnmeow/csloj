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
ll s[105];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    int n, h;
    ll a, ans = 0; cin >> n >> h;
    h/=3; h = 2*h + 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        s[i] = s[i-1] + a;
        if (h < i) ans = max(ans, s[i] - s[i-h]);
        else ans = max(ans, s[i]);
    }
    cout << ans;
    return 0;
}
