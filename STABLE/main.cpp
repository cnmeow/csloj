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
const int MAXN = 10005;
vector<int> a[MAXN];
int d[MAXN], cnt[MAXN];
bool vis[MAXN], check[MAXN];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    memset(d, 0x3f, sizeof(d));
    int n, m, s, u, v; cin >> n >> m >> s;
    while (m--) {
        cin >> u >> v;
        a[u].push_back(v);
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    d[s] = 0;
    cnt[s] = 1;
    while (!pq.empty()) {
        u = pq.top().sc;
        pq.pop();
        vis[u] = true;
        for (int i : a[u])
            if (!vis[i]) {
                if (!check[i] && d[i] == d[u] + 1) {
                    cnt[i]++; check[i] = true; continue;
                }
                if (d[i] > d[u] + 1) {
                    d[i] = d[u] + 1;
                    cnt[i] = cnt[u];
                    pq.push({d[i], i});
                }
                check[i] = true;
            }
        for (int i : a[u]) check[i] = false;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (cnt[i] > 1) ++ans;
    cout << ans;
    return 0;
}
