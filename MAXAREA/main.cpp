#include <bits/stdc++.h>
using namespace std;
int n, ans, f[1005][1005];
string a[1005];
void build(int x)
{
    int l[n+2], r[n+2];
    vector<int> ql;
    ql.push_back(0);
    for (int i = 1; i <= n; ++i){

        while(!ql.empty()){
            if (f[x][i] > f[x][ql[ql.size()-1]]){
                ql.push_back(i);
                l[i] = ql[ql.size()-2] + 1;
                break;
            }
            ql.pop_back();
        }
        if (ql.empty()) ql.push_back(i);
    }
    vector<int> qr;
    qr.push_back(n+1);
    for (int i = n; i > 0; --i){

        while(!qr.empty()){
            if (f[x][i] > f[x][qr[qr.size()-1]]){
                qr.push_back(i);
                r[i] = qr[qr.size()-2] - 1;
                break;
            }
            qr.pop_back();
        }
        if (qr.empty()) qr.push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        ans = max(ans, (r[i] - l[i] + 1)*f[x][i]);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        a[i] = '0'+a[i];
    }
    for (int i = 1; i <= m; ++i)
        for (int j = n; j > 0; --j)
            if (a[i][j] == '1') f[i][j] = f[i-1][j] + 1;
            else f[i][j] = 0;
	for (int i = 1; i <= m; ++i)
        build(i);
    cout << ans;
}
