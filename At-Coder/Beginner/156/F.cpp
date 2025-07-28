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
    int k, q;
    cin >> k >> q;
    vector<int> v(k);
    for(int i=0;i<k;i++) cin >> v[i];
    for(int i=0;i<q;i++){
        int n, x, m;
        cin >> n >> x >> m;
        int ans = 0;
        ll sum = x % m;
        int l = 0, r = ((n-2)/k)*k;
        for(int j=0;j<k;j++){
            ll u = v[j] % m;
            if( u == 0) u = m;
            if(r > (n-2)) r -= k;
            if(r >= l) sum += u * ((r - l)/k + 1);
            l++, r++;
        }
        cout << n - (sum/m + 1) << "\n";
    }
}
