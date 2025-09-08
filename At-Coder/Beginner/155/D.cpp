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
    vector<ll> ng, ps;
    ll zr = 0;
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        if(x > 0) ps.push_back(x);
        if(x < 0) ng.push_back(x);
        if(x == 0) zr++;
    }
    sort(ps.begin(), ps.end());
    sort(ng.begin(), ng.end());
    ll tt = ps.size();
    tt *= ng.size();
    ll ttpzr = zr * (ng.size() + ps.size());
    ttpzr += (zr * (zr-1))/2;
    ttpzr += tt;
    if(tt >= k){
        ll lo = -1e18, hi = -1;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            ll qnt = 0;
            int p = 0;
            for(int i=0;i<ps.size();i++){
                while(p < ng.size() && ng[p] * ps[i] <= mid) p++;
                qnt += p;
            }
            if(qnt >= k) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }else if(ttpzr >= k) cout << "0\n";
    else{
        k -= ttpzr;
        ll lo = 1, hi = 1e18;
        for(auto &x : ng) x = -x;
        reverse(ng.begin(), ng.end());
        auto getqnt = [&](vector<ll> &v, ll num){
            int p = v.size() - 1;
            ll ans = 0;
            for(int i=0;i<v.size();i++){
                while(v[p] * v[i] > num) p--;
                ans += max(0, p - i);
            }
            return ans;
        };
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            //ps ps or ng ng
            ll qnt = getqnt(ps, mid);
            qnt += getqnt(ng, mid);
            if(qnt >= k) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}
