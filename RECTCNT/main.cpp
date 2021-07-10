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
const int MAXM = 1003;
ll l[MAXM], // vi tri trai nhat tren dong dang xet ma h[i] la min
h[MAXM], 
f[MAXM]; // so hcn khi xet den cot j cua dong dang xet
string a[MAXM];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    ll ans = 0;
    int n, m, top; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        stack<int> st; st.push(0);
        for (int j = 1; j <= m; ++j) {
            if (a[i][j-1] == '1') h[j]++;
            else h[j] = 0;
            while (!st.empty()) {
                top = st.top();
                if (h[j] >= h[top]) {
                    st.push(j);
                    l[j] = top + 1;
                    break;
                }
                st.pop();
            }
        }
        for (int j = 1; j <= m; ++j) {
            int k = l[j] - 1;
            f[j] = h[j]*(j-k) + f[k];
            ans += f[j];
        }
    }
    cout << ans;
    return 0;
}
