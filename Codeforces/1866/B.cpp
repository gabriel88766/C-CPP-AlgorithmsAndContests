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
    ll ans = 1;
    map<int,int> mp1, mp2;
    int n, m;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        mp1[v[i]] = aux;
    }
    cin >> m;
    vector<int> u(m);
    for(int i=0;i<m;i++){
        cin >> u[i];
    }
    for(int i=0;i<m;i++){
        int aux;
        cin >> aux;
        mp2[u[i]] = aux;
    }
    bool ok = true;
    for(auto p : mp2){
        if(!mp1.count(p.first)){
            ok = false;
            break;
        }else if(mp1[p.first] < p.second){
            ok = false;
            break;
        }
    }
    if(ok){
        for(auto p : mp1){
            ll x = p.second - mp2[p.first];
            if(x) ans = (ans * 2) % MOD;
        }
        cout << ans << "\n";
    }else cout << "0";
}
