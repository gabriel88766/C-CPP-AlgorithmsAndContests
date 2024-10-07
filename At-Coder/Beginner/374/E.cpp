#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll chp[105][105];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x;
    cin >> n >> x;
    vector<ll> a(n), p(n), b(n), q(n);
    for(int i=0;i<n;i++) cin >> a[i] >> p[i] >> b[i] >> q[i];
    ll lo = 0, hi = 1e18;
    for(int i=0;i<n;i++){
        ll mx1 = x / p[i];
        ll mx2 = x / q[i];
        mx1 *= a[i];
        mx2 *= b[i];
        hi = min(hi, max(mx1, mx2));
    }
    for(int i=0;i<n;i++){
        if(a[i] > b[i]){
            swap(a[i], b[i]);
            swap(p[i], q[i]);
            //a[i] <= b[i] for all i;
        }
    }
    auto calc = [&](ll mid){
        ll cur = 0;
        for(int i=0;i<n;i++){
            if(p[i] >= q[i]){
                //buy b[i] 
                cur += q[i] * ((mid + b[i] - 1) / b[i]);
            }else{
                ll qnt = ((mid + b[i] - 1) / b[i]);
                ll bst = INF_LL;
                for(ll j=qnt; j>= 0;j--){
                    bst = min(bst, j*q[i] + ((max(mid - j*b[i] + a[i] - 1, 0LL))/a[i]) * p[i]);
                }
                cur += bst;
                
            }
        }
        return cur;
    };
    while(lo != hi){
        ll mid = lo + (hi - lo + 1)/2;

        if(calc(mid) <= x) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}
