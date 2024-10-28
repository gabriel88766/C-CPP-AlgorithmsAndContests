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
    int n, m;
    cin >> n >> m;
    vector<ll> v(n+1), ps(n+1), ss(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(i >= 2){
            if(v[i] < v[i-1]) ps[i] = v[i-1] - v[i];
            ps[i] += ps[i-1];
            if(v[i] > v[i-1]) ss[i-1] = v[i] - v[i-1];
        }
    }
    for(int i=n-1;i>=1;i--) ss[i] += ss[i+1];
    for(int i=1;i<=m;i++){
        int l, r;
        cin >> l >> r;
        if(r >= l) cout << ps[r] - ps[l] << "\n";
        else cout << ss[r] - ss[l] << "\n";
    }
}
