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
        int n;
        cin >> n;
        map<ll,ll> mp;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            mp[aux]++;
        }
        int q;
        cin >> q;
        while(q--){
            ll x, y;
            cin >> x >> y;
            ll delta = x*x - 4*y;
            if(delta < 0) cout << "0 ";
            else{
                ll lo = 0, hi = 3e9, mid;
                while(lo != hi){
                    mid = lo + (hi - lo + 1)/2;
                    if(mid*mid <= delta) lo = mid;
                    else hi = mid - 1;
                }
                if(lo*lo != delta || (lo-x) % 2) cout << "0 ";
                else{
                    ll x1 = (x + lo)/2, x2 = (x-lo)/2;
                    if(lo == 0){
                        cout << (mp[x1] * (mp[x1]-1))/2 << " ";
                    }else{
                        cout << (mp[x1] * mp[x2]) << " ";
                    }
                }
            }
        }
        cout << "\n";
    }
}
