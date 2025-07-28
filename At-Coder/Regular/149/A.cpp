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
    //BRUTE FORCE :)
    vector<ll> cg = {0};
    ll n, m;
    cin >> n >> m;
    cg.push_back(1);
    for(int i=2;i<=n;i++){
        cg.push_back((cg.back() * 10) % m);
    }
    ll cur = 0;
    for(auto x : cg) cur += x;
    bool ok = false;
    for(int i=n;i>=1;i--){
        for(int j=9;j>=1;j--){
            if((cur * j) % m == 0){
                ok = true;
                cout << string(i, '0' + j) << "\n";
                break;
            }
        }
        if(ok) break;
        cur -= cg[i];
        cur %= m;
        if(cur < 0) cur += m;
    }
    if(!ok) cout << "-1\n";
}
