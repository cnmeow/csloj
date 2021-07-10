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
ll a[1001][1001], f[1001], ans, s[1001];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
        s[i] = s[i-1] + a[i][i];
    }
    f[1] = s[n];
    for (int i = 2; i <= n; ++i) {
        f[i] = INT_MIN;
        for (int j = 1; j < i; ++j)
            f[i] = max(f[i], f[j] - a[j][1] + a[j][i] - a[i][i] + a[i][1]);
        ans = max(ans, f[i]);
    }
    cout << max(s[n], ans);
    return 0;
}
