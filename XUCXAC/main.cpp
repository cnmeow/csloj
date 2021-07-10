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
const int MAX = 55000000;
struct info{int x, y, b, f, r, cost;};
int mv[2][4] = {{0, 0, 1, -1}, {-1, 1, 0, 0}};
int xt, yt, ans = MAX, n, m, a[55][55], d[55][55][7][7][7];
bool vis[55][55][7][7][7];

info go(int type, info cur) {
    int bot;
    if (type == 0) { // left y-1
        bot = 7-cur.r; cur.r = cur.b; cur.b = bot;
    }
    else if (type == 1) { // right y+1
        bot = cur.r; cur.r = 7-cur.b; cur.b = bot;
    }
    else if (type == 2) { // up x+1
        bot = cur.f; cur.f = 7-cur.b; cur.b = bot;
    }
    else { // down x-1
        bot = 7-cur.f; cur.f = cur.b; cur.b = bot;
    }
    cur.x += mv[0][type]; cur.y += mv[1][type];
    cur.cost = cur.b*a[cur.x][cur.y];
    return cur;
}
bool check(int x, int y) {
    if (x > n || x < 1 || y > m || y < 1) return false;
    return true;
}
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    memset(d, 0x3f, sizeof(d));
    int xs, ys; cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    cin >> xs >> ys >> xt >> yt;
    d[xs][ys][5][1][3] = 5*a[xs][ys];
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({d[xs][ys][5][1][3], 0});
    vector<info> val = {{xs, ys, 5, 1, 3}};
    int cnt = 0;
    while (!pq.empty()) {
        pii u = pq.top();
        pq.pop();
        info cur = val[u.sc];
        int costcur = d[cur.x][cur.y][cur.b][cur.f][cur.r];
        if (cur.x == xt && cur.y == yt)
            ans = min(ans, costcur);
        bool &visited = vis[cur.x][cur.y][cur.b][cur.f][cur.r];
        if (visited) continue;
        visited = true;
        for (int i = 0; i < 4; ++i) {
            info nxt = go(i, cur);
            int &costnxt = d[nxt.x][nxt.y][nxt.b][nxt.f][nxt.r];
            visited = vis[nxt.x][nxt.y][nxt.b][nxt.f][nxt.r];
            if (!visited && check(nxt.x, nxt.y) && costnxt > costcur + nxt.cost) {
                costnxt = costcur + nxt.cost;
                ++cnt;
                val.push_back(nxt);
                pq.push({costnxt, cnt});
            }
        }
    }
    cout << ans;
    return 0;
}
