#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[600005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //if I can normalize, try to just normalize, instead, try all numbers less than max;
    int n;
    ll k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    int mx = *max_element(v.begin(), v.end());
    for(int i=1;i<=2*mx + 1;i++) cnt[i] += cnt[i-1];
    
    ll dif = 0;
    for(int i=0;i<n;i++){
        dif += mx - v[i];
    }
    if(dif <= k){
        k -= dif;
        cout << mx + k/n << "\n";
    }else{
        //solve. naive is O(n * mx) try anything better.
        //O(n log^2 n) but O(n log n) after counting sort
        sort(v.begin(), v.end());
        vector<ll> ps(n+1);
        for(int i=0;i<n;i++){
            ps[i+1] = ps[i] + v[i];
        }
        int ans = 1;
        for(int i=1;i<=mx;i++){
            ll cur = 0;
            for(int j=1;i*(j-1) <= mx; j++){ //asserting all multiples will be 
                ll fst = cnt[i*(j-1)];
                ll lst = cnt[i*j];
                cur += (lst-fst) * (i*j) - (ps[lst] - ps[fst]);
            }
            if(cur <= k) ans = i;
        }
        cout << ans << "\n";

    }
}
