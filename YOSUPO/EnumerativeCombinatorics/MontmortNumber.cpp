#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
ll ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, M;
    cin >> n >> M;
    ans[0] = 1;
    for(ll i=1;i<=n;i++){
        ans[i] = (ans[i-1] * i) % M;
        if(i % 2) ans[i]--;
        else ans[i]++;
        ans[i] = (ans[i] + M) % M;
        cout << ans[i] << " ";
    }
}
