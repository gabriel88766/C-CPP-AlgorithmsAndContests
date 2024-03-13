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
        ll n, k;
        cin >> n >> k;
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++) cin >> vp[i].first;
        for(int i=0;i<n;i++) cin >> vp[i].second;
        sort(vp.begin(), vp.end(), [&](pair<int,int> &u, pair<int,int> &v){
            return abs(u.second) < abs(v.second);
        });
        bool ok = true;
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum += vp[i].first;
            ll cur = abs(vp[i].second);
            cur *= k;
            if(sum > cur) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
