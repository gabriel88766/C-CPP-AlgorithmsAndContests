#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int vis[200005];
ll w[200005];
ll ps[200005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q, x;
    cin >> n >> q >> x;
    for(int i=0;i<n;i++) cin >> w[i];
    ps[0] = w[0];
    for(int i=1;i<n;i++) ps[i] = ps[i-1] + w[i];
    vector<ll> qt;
    vector<ll> bg;
    int cur = 0;
    while(!vis[cur]){
        vis[cur] = qt.size() + 1;
        bg.push_back(cur);
        ll lo = 1, hi = 1e9+1;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            ll S = 0;
            S += ps[n-1] * (mid/n);
            ll r = mid % n;
            if(r + cur - 1 >= n){
                S += ps[n-1];
                if(cur > 0) S -= ps[cur-1];
                S += ps[(r+cur-1)%n];
            }else{
                S += ps[r+cur-1];
                if(cur > 0) S -= ps[cur-1];
            }
            if(S >= x) hi = mid;
            else lo = mid + 1;
        }
        qt.push_back(lo);
        cur = (lo + cur) % n;
    }

    int rp = qt.size() + 1;
    for(int i=0;i<q;i++){
        ll k;
        cin >> k;
        ll mod = rp - vis[cur];
        if(k <= vis[cur]) cout << qt[k-1] << "\n";
        else{
            k -= vis[cur];
            k %= mod;
            cout << qt[vis[cur] + k - 1] << "\n";
        }
    }
}
