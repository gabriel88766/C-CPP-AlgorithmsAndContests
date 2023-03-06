#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<ll> v(n+1), ps(n+1, 0);
    for(int i=1;i<=n;i++) cin >> v[i];
    sort(v.begin()+1, v.end(), greater<int>());
    for(int i=1;i<=n;i++) ps[i] = ps[i-1]+v[i];
    for(int i=0;i<q;i++){
        int x, y;
        cin >> x >> y;
        cout << ps[x]-ps[x-y] << "\n";
    }
}
