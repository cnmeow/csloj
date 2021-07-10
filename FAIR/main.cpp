#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pip pair<int, pii >
#define fr first
#define sc second
#define camnguyenmeow ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define PROBLEMS            ""
/*   /\_/\
    (= ._.)
    / >?  \>$
    *dr[] - row, dc[] - column: 0-right, 1-left, 2-up, 3-down
*/
const int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
int d[1005][1005], c[1005][1005];
bool vis[1005][1005];
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    memset(d, 0x3f, sizeof(d));
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> c[i][j];
    priority_queue<pip, vector<pip>, greater<pip> > pq;
    for (int i = 1; i <= n; ++i) {
        pq.push({1, {i, 1}});
        d[i][1] = 1;
    }
    auto ok = [&] (int x1, int x2) {
        if (x1 > 0 && x1 <= n && x2 > 0 && x2 <= m) return true;
        return false;
    };
    int x, y, cost;
    while (!pq.empty()) {
        pii i = pq.top().sc; pq.pop();
        vis[i.fr][i.sc] = true;
        for (int z = 0; z < 4; ++z) {
            x = i.fr + dr[z];
            y = i.sc + dc[z];
            if (!ok(x, y) || vis[x][y]) continue;
            if (c[x][y] == c[i.fr][i.sc]) cost = 0;
            else cost = 1;
            if (d[x][y] > d[i.fr][i.sc] + cost) {
                d[x][y] = d[i.fr][i.sc] + cost;
                pq.push({d[x][y], {x, y}});
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, d[i][m]);
    cout << ans;
    return 0;
}
