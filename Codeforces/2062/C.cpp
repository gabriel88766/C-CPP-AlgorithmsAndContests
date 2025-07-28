#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll getsum(vector<ll> &v){
    ll sum = 0;
    for(auto x : v) sum += x;
    return sum;
}
void apply(vector<ll> &v){
    for(int i=0;i<v.size()-1;i++){
        v[i] = v[i+1] - v[i];
    }
    v.resize(v.size() - 1);
}
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
        vector<ll> v(n);
        queue<vector<ll>> q;
        map<vector<ll>, bool> vis;
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        vis[v] = true;
        q.push(v);
        ll ans = -INF_LL;
        while(q.size()){
            auto ux = q.front();
            q.pop();
            ans = max(ans, getsum(ux));
            auto au = ux;
            if(au.size() == 1) continue;
            reverse(au.begin(), au.end());
            if(!vis.count(au)){
                q.push(au);
                vis[au] = true;
            }
            au = ux;
            apply(au);
            if(!vis.count(au)){
                q.push(au);
                vis[au] = true;
            }
        }
        cout << ans << "\n";
    }
}
