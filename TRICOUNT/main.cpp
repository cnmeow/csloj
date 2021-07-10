#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
#define camnguyenmeow ios_base::sync_with_stdio(false);cout.tie(0);cout.tie(0);
//#define PROBLEMS            ""
/*   /\_/\
    (= ._.)
    / >?  \>$
*/
int a[8005];
int main()
{
    camnguyenmeow;
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(&a[1], &a[n+1]);
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            int z = i;
            for (int j = 1; j < i; ++j) {
                while (a[j] + a[i] > a[z+1] && z < n) ++z;
                ans  = ans + (z-i);
            }
        }
        cout << ans <<'\n';
        return 0;
}
