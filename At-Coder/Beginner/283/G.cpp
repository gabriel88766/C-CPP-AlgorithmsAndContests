#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll xorb[64];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, l, r;
    cin >> n >> l >> r;
    vector<int> bs;
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        while(x && xorb[63 - __builtin_clzll(x)]){
            x ^= xorb[63 - __builtin_clzll(x)];
        }
        if(x != 0){
            xorb[63 - __builtin_clzll(x)] = x;
            bs.push_back(63 - __builtin_clzll(x));
        }
    }
    sort(bs.begin(), bs.end());
    l--;
    r--;
    for(ll i=l;i<=r;i++){
        ll num = 0;
        for(int j=bs.size()-1;j>=0;j--){
            // cout << bs[j] << " ";
            ll a = num ^ xorb[bs[j]];
            if(i & (1LL << j)){
                if(a > num) num = a;
            }else{
                if(a < num) num = a;
            }
        }
        // cout << "\n";
        cout << num << " ";
    }
    cout << "\n";
}
