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
const int MAXN = 30001;
int d[MAXN], cnt[MAXN], haha[MAXN];
bool vis[MAXN];
vector<pii> a[MAXN];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    memset(d, 0x3f, sizeof(d));
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v, z; cin >> u >> v >> z;
        a[u].push_back({v, z});
        a[v].push_back({u, z});
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 1});
    d[1] = 0;
    cnt[1] = 1;
    while (!pq.empty()) {
        int u = pq.top().sc;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (pii v : a[u])
            if (!vis[v.fr]) {
                if (d[v.fr] == d[u] + v.sc)
                    cnt[v.fr] += cnt[u];
                else if (d[v.fr] > d[u] + v.sc) {
                    cnt[v.fr] = cnt[u];
                    d[v.fr] = d[u] + v.sc;
                    pq.push({d[v.fr], v.fr});
                }
            }
    }
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (pii v : a[u])
            if (d[u] == d[v.fr] + v.sc) {
                haha[u] += cnt[v.fr];
                q.push(v.fr);
            }
    }
    vector<int> ans;
    for (int i = 2; i < n; ++i)
        if (haha[i] < cnt[n]) ans.push_back(i);
    cout << ans.size() <<'\n';
    for (int i : ans) cout << i <<'\n';
    return 0;
}
