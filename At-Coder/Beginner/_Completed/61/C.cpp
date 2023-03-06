#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll cnt[100005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        ll a, b;
        cin >> a >> b;
        cnt[a] += b;
    }
    for(int i=1;i<=100000;i++){
        if(cnt[i] >= k){
            cout << i;
            return 0;
        }
        k -= cnt[i];
    }
}
