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
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    vector<ll> cnt(x+1, 0);
    for(int i=0;i<n;i++){
         cin >> v[i];
         cnt[v[i]]++;
    }
    bool ok = true;
    for(int i=1;i<x;i++){
        if(cnt[i]){
            if(cnt[i] % (i+1)){
                ok = false; break;
            }else{
                cnt[i+1] += (cnt[i]/(i+1));
            }
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";

}
