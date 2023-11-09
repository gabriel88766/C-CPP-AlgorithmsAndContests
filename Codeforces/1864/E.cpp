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
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<vector<ll>> v(30, vector<ll>());
        vector<ll> pos(5, 0);
        ll cnt0 = 0;
        for(ll i=0;i<n;i++){
            ll aux;
            cin >> aux;
            if(aux == 0) cnt0++;
            else for(ll j=0;j<30;j++){
                if(aux < (1 << (j+1))){
                    v[j].push_back(aux);
                    break;
                }
            }
        }
        
        pos[1] += 2*cnt0*n - cnt0*cnt0;
        ll S = cnt0;
        for(int i=0;i<30;i++){
            ll x = v[i].size();
            S += x;
            int cnt2i = 0;
            for(int j=0;j<v[i].size();j++){

            }
            pos[1] += x*(n-S); //a < b, a < 2^(i+1)
            pos[2] += x*(n-S); //b < a, b
        }
    }
}
