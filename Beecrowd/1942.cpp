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
    int n, k;
    cin >> n >> k;
    vector<ll> v;
    bool zr = false;
    for(int i=0;i<n;i++){
        ll cur = 0;
        for(int j=0;j<k;j++){
            int aux;
            cin >> aux;
            if(aux % 2) cur ^= (1LL << j);
        }
        if(cur) v.push_back(cur);
        else zr = true;
    }
    set<ll> s;
    for(int i=0;i<v.size();i++){
        ll cur = v[i];
        if(s.size()){
            while(cur){
                bool ok = true;
                for(auto x : s){
                    if(__builtin_clzll(x) == __builtin_clzll(cur)){
                        cur ^= x;
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    s.insert(cur);
                    break;
                }
            }
            if(cur == 0) zr = true;
        }else s.insert(cur);
    }
    if(s.size() == k && zr) cout << "N\n";
    else cout << "S\n";

}
