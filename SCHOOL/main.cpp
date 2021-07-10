#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef pair<int,int> pii;
const int MAXN = 100001;
struct info{int v, ac, bc;};
vector<pii> e[MAXN];
vector<info> a[MAXN];
int wt[MAXN], ot[MAXN], ot_ton[MAXN];
bool vis[MAXN];
int main()
{
    //freopen("school.inp","r",stdin);
    memset(wt, 0x3f, sizeof(wt));
    memset(ot_ton, 0x3f, sizeof(ot_ton));
    memset(ot, 0x3f, sizeof(ot));
    int n, m, k; cin >> n >> m >> k;
    while (m--) {
        int u, v, ac, bc; cin >> u >> v >> ac >> bc;
        e[u].push_back({v, bc});
        a[v].push_back({u, ac, bc});
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 1});
    ot[1] = 0;
    while (!pq.empty()) {
        pii s = pq.top();
        pq.pop();
        if (vis[s.sc]) continue;
        vis[s.sc] = true;
        for (pii t : e[s.sc])
            if (!vis[t.fr] && ot[t.fr] > ot[s.sc] + t.sc) {
                ot[t.fr] = ot[s.sc] + t.sc;
                pq.push({ot[t.fr], t.fr});
            }
    }
    memset(vis, 0, sizeof(vis));

    pq.push({0, k});
    wt[k] = 0;
    while (!pq.empty()) {
        pii s = pq.top();
        pq.pop();
        if (vis[s.sc]) continue;
        vis[s.sc] = true;
        for (info t : a[s.sc])
            if (!vis[t.v] && wt[t.v] > wt[s.sc] + t.ac) {
                wt[t.v] = wt[s.sc] + t.ac;
                pq.push({wt[t.v], t.v});
            }
    }
    memset(vis, 0, sizeof(vis));

    pq.push({0, n});
    ot_ton[n] = 0;
    while (!pq.empty()) {
        pii s = pq.top();
        pq.pop();
        if (vis[s.sc]) continue;
        vis[s.sc] = true;
        for (info t : a[s.sc])
            if (!vis[t.v] && ot_ton[t.v] > ot_ton[s.sc] + t.bc) {
                ot_ton[t.v] = ot_ton[s.sc] + t.bc;
                pq.push({ot_ton[t.v], t.v});
            }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        if (ot[i] + wt[i] <= 59) {
            ans = min(ans, ot[i] + ot_ton[i]);
        }
    }
    cout << ans;
}
