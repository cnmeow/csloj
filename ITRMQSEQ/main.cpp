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
int st[1000005][25];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    memset(st, 0x3f, sizeof(st));
    int n, Q; cin >> n >> Q;
    int k = log2(n) + 1;
    for (int i = 0; i < n; ++i) cin >> st[i][0];
    for (int j = 1; j <= k; ++j)
        for (int i = 0, maxi = n-(1<<j); i <= maxi; ++i)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    int L, R, j;
    while (Q--) {
        cin >> L >> R;
        L--; R--;
        j = int(log2(R - L + 1));
        cout << min(st[L][j], st[R - (1 << j) + 1][j]) <<' ';
    }
    return 0;
}
