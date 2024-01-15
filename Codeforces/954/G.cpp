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
    ll n, r, k;
    cin >> n >> r >> k;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<ll> rl(n);
    for(int i=0;i<=min(r, n-1);i++) rl[0] += v[i];
    int p = min(r, n-1);
    for(int i=1;i<n;i++){
        rl[i] = rl[i-1];
        if(p < n-1){
            p++;
            rl[i] += v[p];
        }
        if(i - r - 1 >= 0) rl[i] -= v[i - r - 1];
    }
    ll val = *min_element(rl.begin(), rl.end());
    ll lo = val, hi = val + k;
    while(lo != hi){
        ll mid = lo + (hi - lo + 1)/2;
        auto vec = rl;
        ll curp = 0;
        queue<pair<ll, ll>> qp;
        ll curs = 0;
        for(int i=0;i<vec.size();i++){
            if(vec[i] + curp < mid){
                ll pls = mid - curp - vec[i];
                qp.push({i+2*r, pls});
                curp += pls;
                curs += pls;
                if(curs > k) break; //overflow
            }
            if(qp.size() && qp.front().first == i){
                curp -= qp.front().second;
                qp.pop();
            }
        }
        if(curs <= k) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}   
