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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        int p = 0;
        ll ans = 0;
        while(p < n){
            int p2 = p;
            while(p2 + 1 < n && v[p2+1] == v[p]) p2++;
            ll c = p2 - p + 1;
            ans += (c * (c-1)) / 2;
            p = p2 = p2+1;
        }
        ll c1  = 0, c2 = 0;
        for(int i=0;i<n;i++){
            if(v[i] == 1) c1++;
            if(v[i] == 2) c2++;
        }
        ans += c1*c2;
        cout << ans << "\n";
    }
}
