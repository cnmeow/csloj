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
const int MAXN = 1e6;
ll a[MAXN];
int l[MAXN], r[MAXN];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    int n, top; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    stack<int> st;
    st.push(0);
    for (int i = 1; i <= n; ++i)
        while (!st.empty()) {
            top = st.top();
            if (a[i] > a[top]) {
                st.push(i);
                l[i] = top + 1;
                break;
            }
            st.pop();
        }
    st.push(n+1);
    for (int i = n; i > 0; --i)
        while (!st.empty()) {
            top = st.top();
            if (a[i] > a[top]) {
                st.push(i);
                r[i] = top - 1;
                break;
            }
            st.pop();
        }
    ll ans = 0, s;
    for (int i = 1; i <= n; ++i) {
        s = (r[i] - l[i] + 1)*a[i];
        ans = max(ans, s);
    }
    cout << ans;
    return 0;
}
