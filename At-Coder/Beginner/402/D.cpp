#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e6+3;
int cnt[N];
ll cs(ll n){
    return (n*(n-1))/2;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        int s = a + b;
        if(s >= n) s -= n;
        cnt[s]++;
    }
    ll ans = cs(m);
    for(int i=0;i<n;i++){
        ans -= cs(cnt[i]);
    }
    cout << ans << "\n";
}
