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
        ll n, m;
        cin >> n >> m;
        vector<ll> v(n*m);
        for(int i=0;i<n*m;i++) cin >> v[i];
        sort(v.begin(), v.end());
        int sz = n*m;
        ll maxv = (v[sz-1] - v[0])*max(n-1,m-1) + (v[sz-1] - v[1])*min(n-1,m-1) + (n-1)*(m-1)*(v[sz-1]-v[0]);
        maxv = max(maxv, (v[sz-1] - v[0])*max(n-1,m-1) + (v[sz-2] - v[0])*min(n-1,m-1) + (n-1)*(m-1)*(v[sz-1]-v[0]));
        cout << maxv << "\n";
    }
}
