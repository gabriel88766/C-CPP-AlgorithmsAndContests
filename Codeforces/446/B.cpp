#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
ll gr[N][N];
ll br[N*N], bc[N*N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m, k, p;
    cin >> n >> m >> k >> p;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> gr[i][j];
        }
    }
    //for rows
    priority_queue<ll> pq;
    for(int i=1;i<=n;i++){
        ll sum = 0;
        for(int j=1;j<=m;j++) sum += gr[i][j];
        pq.push(sum);
    }
    for(int i=1;i<=k;i++){
        auto u = pq.top();
        pq.pop();
        br[i] = br[i-1] + u;
        pq.push(u - p*m);
    }
    while(pq.size()) pq.pop();
    //for columns
    for(int j=1;j<=m;j++){
        ll sum = 0;
        for(int i=1;i<=n;i++) sum += gr[i][j];
        pq.push(sum);
    }
    for(int i=1;i<=k;i++){
        auto u = pq.top();
        pq.pop();
        bc[i] = bc[i-1] + u;
        pq.push(u - p*n);
    }
    ll ans = -INF_LL;
    for(int i=0;i<=k;i++){
        ll cur = br[i] + bc[k-i];
        ans = max(ans, cur - p * i * (k-i));
    }
    cout << ans << "\n";
}
