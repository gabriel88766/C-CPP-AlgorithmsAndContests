#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll n;
void func(const vector<ll> &v, ll &cnt, ll aux, ll l, ll r){
    while(aux && (l != 0 || r != (n-1))){
        if(l >= n-r-1){
            if((aux - (v[l] - v[l-1])) >= 0){
                cnt -= (v[l] - v[l-1]) * l;
                aux -= (v[l] - v[l-1]);
                l--;
            }else{
                cnt -= aux * l;
                aux = 0;
            }
        }else{
            if((aux - (v[r+1] - v[r])) >= 0){
                cnt -= (v[r+1]-v[r]) * (n-r-1);
                aux -= (v[r+1]-v[r]);
                r++;
            }else{
                cnt -= aux * (n - r - 1);
                aux = 0;
            }
        }
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll m1 = x[n/2], m2 = y[n/2];
    ll hi = max(x.back() - x[0], y.back() - y[0]), lo = 0;
    ll cnt1 = 0, cnt2 = 0;
    for(auto v : x){
        cnt1 += abs(v - m1);
    }
    for(auto v : y){
        cnt2 += abs(v - m2);
    }
    while(lo != hi){
        ll mid = lo + (hi - lo) / 2;
        ll cnt = cnt1 + cnt2;
        func(x, cnt, mid, n/2, n/2);
        func(y, cnt, mid, n/2, n/2);
        if(cnt <= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}
