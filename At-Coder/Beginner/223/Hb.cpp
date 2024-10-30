#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e5+3;
ll basis[N][64];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<vector<int>> bs(n+1);
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            ll cur = a[i];
            while(cur && basis[j][__builtin_clzll(cur)]){
                cur ^= basis[j][__builtin_clzll(cur)];
            }
            if(cur){
                basis[j][__builtin_clzll(cur)] = cur;
                bs[j].push_back(i);
            }else break;
        }
    }
    
    for(int i=1;i<=q;i++){
        ll l, r, x;
        cin >> l >> r >> x;
        vector<int> btc;
        for(auto k : bs[l]){
            if(k <= r) btc.push_back(k);
            else break;
        }
        vector<ll> cb(64, 0);
        for(auto j : btc){
            ll cur = a[j];
            while(cur && cb[__builtin_clzll(cur)]){
                cur ^= cb[__builtin_clzll(cur)];
            }
            if(cur){
                cb[__builtin_clzll(cur)] = cur;
            }
        }
        ll cur = x;
        while(cur && cb[__builtin_clzll(cur)]){
            cur ^= cb[__builtin_clzll(cur)];
        }
        if(cur == 0) cout << "Yes\n";
        else cout << "No\n";
    }


}
