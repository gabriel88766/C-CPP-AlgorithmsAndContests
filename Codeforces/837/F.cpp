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
    ll n, k;
    cin >> n >> k;
    bool ok = false, bg = false;
    vector<ll> v;
    for(int i=1;i<=n;i++){
        ll x;
        cin >> x;
        if(x >= k) ok = true;
        if(x > 0 || bg){
            bg = true;
            v.push_back(x);
        }
    }
    if(ok){
        cout << "0\n";
        return 0;
    }
    if(v.size() == 2){//simulation will be linear
        ll na = v[0];
        ll nb = v[1];
        cout << (k - nb + na - 1) / na << "\n";
    }else if(v.size() == 3){ //simulation will be O(sqrt(n))
        ll na = v[0];
        ll nb = v[1];
        ll nc = v[2];
        ll lo = 1, hi = 2e9;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            ll m1 = mid * (mid + 1);
            m1 /= 2;
            ll cur = nc + mid * nb;
            if((INF_LL-cur)/m1 >= na) cur = cur + m1 * na;
            else cur = INF_LL;
            if(cur >= k) hi = mid;
            else lo = mid + 1; 
        }
        cout << lo << "\n";
    }else{ //simulation allowed
        for(int i=1;;i++){
            assert(i*v.size() <= 20'000'000);
            for(int j=1;j<v.size();j++){
                v[j] += v[j-1];
                if(v[j] >= k){
                    ok = true;
                    break;
                }
            }
            if(ok){
                cout << i << "\n";
                break;
            }
        }
    }
}
