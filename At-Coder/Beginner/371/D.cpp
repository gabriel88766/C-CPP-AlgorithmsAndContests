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
    int n, q;
    cin >> n;
    vector<int> v(n+1);
    vector<ll> ps(n+1);
    v[0] = -INF_INT;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        cin >> ps[i];
        ps[i] += ps[i-1];
    }
    cin >> q;
    for(int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        auto it1 = prev(lower_bound(v.begin(), v.end(), r+1)) - v.begin();
        auto it2 = prev(lower_bound(v.begin(), v.end(), l)) - v.begin();
        cout << ps[it1] - ps[it2] << "\n";
    }
}
  