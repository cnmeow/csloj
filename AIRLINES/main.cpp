#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pip pair<int,pii >
#define fr first
#define sc second
#define camnguyenmeow ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define PROBLEMS            ""
/*   /\_/\
    (= ._.)
    / >?  \>$
*/
vector<pii> e[105];
int d[105][20];
pii par[105][20];
bool vis[105][20];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    memset(d, 0x3f, sizeof(d));
    int n, m, c, a, s, t, u, v, k;
    cin >> n >> m >> c >> a >> s >> t;
    while (m--) {
        cin >> u >> v >> k;
        e[u].push_back({v, k});
        e[v].push_back({u, k});
    }
    priority_queue<pip, vector<pip>, greater<pip> > pq;
    for (pii i : e[s]) {
        pq.push({0, {s, i.sc}});
        d[s][i.sc] = 0;
    }
    while (!pq.empty()) {
        pii i = pq.top().sc;
        pq.pop();
        for (pii j : e[i.fr]) {
            if (j.sc == i.sc && d[j.fr][j.sc] > d[i.fr][i.sc] + c) {
                d[j.fr][j.sc] = d[i.fr][i.sc] + c;
                par[j.fr][j.sc] = {i.fr, i.sc};
                pq.push({d[j.fr][j.sc], {j.fr, j.sc}});
                continue;
            }
            if (j.sc != i.sc && d[j.fr][j.sc] > d[i.fr][i.sc] + c + a) {
                d[j.fr][j.sc] = d[i.fr][i.sc] + c + a;
                par[j.fr][j.sc] = {i.fr, i.sc};
                pq.push({d[j.fr][j.sc], {j.fr, j.sc}});
            }
        }
    }
    vector<pip> ans;
    int minn = INT_MAX, savek, p;
    for (int i = 1; i <= 16; ++i)
        if (d[t][i] < minn) {
            minn = d[t][i];
            savek = i;
        }
    for (int i = t, j = savek; i != s; ) {
        p = par[i][j].fr;
        ans.push_back({p, {i, j}});
        j = par[i][j].sc; i = p; p = par[p][j].fr;
    }
    reverse(ans.begin(), ans.end());
    cout << minn <<'\n';
    for (pip i : ans)
        cout << i.fr <<' '<< i.sc.fr <<' '<< i.sc.sc <<'\n';
    return 0;
}
