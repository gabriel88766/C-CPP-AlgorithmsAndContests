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
    ll n, m;
    cin >> n >> m;
    vector<ll> hl, vl;
    ll ans = n*n;
    vector<pair<ll,ll>> d1, d2;
    for(int i=1;i<=m;i++){
        // each queen add 4 lines, check intersections
        ll x, y;
        cin >> x >> y;
        swap(x, y);
        hl.push_back(y);
        vl.push_back(x);
        d1.push_back({x - min(x-1, y-1), y - min(x-1, y-1)});
        d2.push_back({x - min(x-1, n-y), y + min(x-1, n-y)});   
    }
    sort(d1.begin(), d1.end());
    d1.resize(unique(d1.begin(), d1.end()) - d1.begin());
    sort(d2.begin(), d2.end());
    d2.resize(unique(d2.begin(), d2.end()) - d2.begin());
    sort(hl.begin(), hl.end());
    hl.resize(unique(hl.begin(), hl.end()) - hl.begin());
    sort(vl.begin(), vl.end());
    vl.resize(unique(vl.begin(), vl.end()) - vl.begin());
    //diagonals first
    for(auto [a, b] : d2){
        ans -= min(n-a+1, b);
    }
    for(auto [a, b] : d1){
        ans -= min(n-a+1, n-b+1);
        vector<ll> ints;
        for(auto [aa, bb] : d2){
            //there is some k
            //a + k == aa + u, b + k == bb - u
            // u and k are positive
            // k - u = aa - a
            // k + u == bb - b
            // 2k = aa + bb - a - b
            // 2u = bb - b - aa + a
            ll x1 = aa + bb - a - b;
            ll x2 = bb + a - aa - b;
            if(x1 >= 0 && x2 >= 0 && (!(x1 % 2)) && (!(x2 % 2))){
                if(a + x1/2 <= n && b + x1/2 <= n) ints.push_back(x1/2);
            }
        }
        sort(ints.begin(), ints.end());
        ints.resize(unique(ints.begin(), ints.end()) - ints.begin());
        ans += ints.size();
    }
    //now horizontals
    for(auto y : hl){
        ans -= n;
        vector<ll> ints;
        for(auto [a, b] : d1){
            //a + k == x, b + k = y => k = y-b
            int k = y - b;
            if(k >= 0 && a + k <= n) ints.push_back(a + k);
        }
        for(auto [a, b] : d2){
            //a + k == x && b - k = y => k = b-y;
            int k = b - y;
            if(k >= 0 && a + k <= n) ints.push_back(a + k);
        }
        sort(ints.begin(), ints.end());
        ints.resize(unique(ints.begin(), ints.end()) - ints.begin());
        ans += ints.size();
    }
    //verticals

    for(auto x : vl){
        ans -= n;
        vector<ll> ints;
        for(auto [a, b] : d1){
            //a + k == x, b + k = y => k = x-a
            int k = x - a;
            if(k >= 0 && b + k <= n) ints.push_back(b + k);
        }
        for(auto [a, b] : d2){
            //a + k == x && b - k = y => k = b-y;
            int k = x - a;
            if(k >= 0 && b - k >= 1) ints.push_back(b - k);
        }
        for(auto y : hl) ints.push_back(y);
        sort(ints.begin(), ints.end());
        ints.resize(unique(ints.begin(), ints.end()) - ints.begin());
        ans += ints.size();
    }




    cout << ans << "\n";
}
