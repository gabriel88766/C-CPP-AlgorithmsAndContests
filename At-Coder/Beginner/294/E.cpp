#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Interval{
    ll l, r, val;
};


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll l, n, m;
    cin >> l >> n >> m;
    ll curl = 1;
    vector<Interval> u(n), v(m);
    for(int i=0;i<n;i++){
        ll a, b;
        cin >> a >> b;
        Interval p = {curl, curl+b-1, a};
        u[i] = p;
        curl += b;
    }
    curl = 1;
    for(int i=0;i<m;i++){
        ll a, b;
        cin >> a >> b;
        Interval p = {curl, curl+b-1, a};
        v[i] = p;
        curl += b;
    }
    int p1 = 0, p2 = 0;
    ll ans = 0;
    while(p1 < n && p2 < m){
        if(u[p1].val == v[p2].val){
            ans += min(u[p1].r, v[p2].r) - max(u[p1].l, v[p2].l)+1; 
        }
        if(u[p1].r < v[p2].r) p1++;
        else if(u[p1].r > v[p2].r) p2++;
        else p1++,p2++;
    }
    cout << ans;
}
