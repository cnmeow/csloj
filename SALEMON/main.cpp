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
const int MAXN = 1000005;
int h[MAXN], l[MAXN], h2[MAXN], r[MAXN];
ll ans, s;
int main()
{
    camnguyenmeow;
    int n, top; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        h2[i] = h[i];
    }
    sort(&h2[1], &h2[n+1]);
    stack<int> st; st.push(0);
    for (int i = 1; i <= n; ++i) {
        while (!st.empty()) {
            top = st.top();
            if (h[i] > h[top]) {
                st.push(i);
                l[i] = top+1;
                break;
            }
            st.pop();
        }
    }
    st.push(n+1);
    for (int i = n; i > 0; --i) {
        while (!st.empty()) {
            top = st.top();
            if (h[i] > h[top]) {
                st.push(i);
                 r[i] = top-1;
                break;
            }
            st.pop();
        }
    }
    for (int i = 1; i <= n; ++i) {
        int len = r[i] - l[i] + 1;
        if (len >= h[i]) {
            ll tmp = h[i]; tmp *= tmp;
            ans = max(ans, tmp);
            continue;
        }
        int lwb = lower_bound(&h2[1], &h2[n+1], len) - &h2[0];
        if (h2[lwb] <= len) {
            ll tmp = h2[lwb]; tmp *= tmp;
            ans = max(ans, tmp); continue;
        }
        if (lwb > 1 && h2[lwb] <= len) {
            ll tmp = h2[lwb-1]; tmp *= tmp;
            ans = max(ans, tmp);
        }
    }
    cout << ans;
}
