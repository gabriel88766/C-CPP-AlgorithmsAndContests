#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<ll> cnt(n+1, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j] == 'o') cnt[j]++;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        vector<int> co;
        for(int j=0;j<n;j++){
            if(v[i][j] == 'o') co.push_back(j);
        }
        //each j in co.size() - 1 duos
        ll aux = co.size() - 1;
        for(auto x : co) ans += (aux*cnt[x]);
        ans -= (aux*(aux+1));
    }
    cout << ans << "\n";
}
