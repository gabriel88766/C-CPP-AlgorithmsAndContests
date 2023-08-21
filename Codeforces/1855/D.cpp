#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<200005> bs[2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n+1, 0), ps(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> v[i]; 
        ps[i] = ps[i-1] + v[i];
    }
    ll ans = 0;
    if(v[1] == 0){
        cout << 0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i == 1){
            ans = v[1];
            bs[0][v[1]+1] = 1;
            continue;
        }
        else{
            bs[1] = (bs[0] >> (i-1));
            bs[1][0] = 0;
            bs[1] <<= (i-1);
            bs[1] |= (bs[1] << v[i]);
        }
        int pos = bs[1]._Find_first();
        if(pos != 200005) ans = max(ans, ps[i]-pos+1);
        bs[0] = bs[1];
    }
    cout << ans;

}
