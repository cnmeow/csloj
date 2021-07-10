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
using namespace std;
const int MOD = 1e9+9, MAXN = 1e5+5;
pii a[MAXN];
int f[MAXN], dp[MAXN], v[MAXN], top;
bool cmp1(pii x , pii y) {
	return x.fr < y.fr;
}
bool cmp2(pii x, pii y) {
    return x.sc < y.sc;
}
void add(int p , int x)
{
	int i;
	for(i = p ; i <= top ; i += i & (-i))
		f[i] = (f[i] + x) % MOD;
}
int query(int p)
{
	int i , ans = 0;
	for(i = p ; i ; i -= i & (-i))
		ans = (ans + f[i]) % MOD;
	return ans;
}
int main()
{
	int n, i, t;
	scanf("%d" , &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d" , &t); a[i].fr = a[i - 1].fr + t , a[i].sc = i;
	}
	sort(a , a + n + 1 , cmp1);
	v[0] = -INT_MAX;
	for(i = 0 ; i <= n ; i ++ )
	{
		if(a[i].fr != v[top]) v[++top] = a[i].fr;
		a[i].fr = top;
	}
	sort(a , a + n + 1 , cmp2);
	dp[0] = 1;
	add(a[0].fr , 1);
	for(i = 1 ; i <= n ; i ++ )
		dp[i] = query(a[i].fr) , add(a[i].fr , dp[i]);
	printf("%d" , dp[n]);
	return 0;
}
