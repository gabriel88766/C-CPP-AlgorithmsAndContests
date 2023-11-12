#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Interval{
    ll w, l, r;
    bool operator< (const Interval &u) const{
        if(abs(w) != abs(u.w)) return abs(w) < abs(u.w);
        else return l < u.l;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    vector<ll> v(n), ansv;
    for(int i=0;i<n;i++) cin >> v[i];
    queue<int> q;
    map<int,int> d;
    for(int i=0;i<n;i++){
        d[v[i]] = 0;
        q.push(v[i]);
    }
    int cnt = 0;
    while(cnt < m){
        auto u = q.front();
        q.pop();
        int v1 = u+1;
        int v2 = u-1;
        if(!d.count(v1)){
            d[v1] = d[u] + 1;
            ans += d[v1];
            cnt++;
            ansv.push_back(v1);
            q.push(v1);
        }
        if(cnt != m && !d.count(v2)){
            d[v2] = d[u] + 1;
            ans += d[v2];
            ansv.push_back(v2);
            cnt++;
            q.push(v2);
        }
    }
    cout << ans << "\n";
    for(auto x : ansv) cout << x << " ";
}
