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
const int MAXN = 1e5+5;
vector<int> a[MAXN];
int n, m, cnt;
bool vis[MAXN];
void dfs(int u) {
    ++cnt;
    for (int v : a[u])
        if (!vis[v]) {
            vis[v] = true;
            dfs(v);
        }
}
int main()
{
    camnguyenmeow;
    #ifdef PROBLEMS
        freopen(PROBLEMS".inp","r",stdin);
        freopen(PROBLEMS".out","w",stdout);
    #endif
    cin >> n >> m;
    int u, v;
    while (m--) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vis[1] = true;
    dfs(1);
    int ans1 = cnt, ans2 = 0;
    cnt = 0;
    for (int i = 2; i <= n; ++i)
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
            ans2 = max(ans2, cnt);
            cnt = 0;
        }
    cout << ans1 + ans2;
    return 0;
}
