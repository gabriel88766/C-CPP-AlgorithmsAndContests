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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        ll ans = 0;
        if(!(n % 2)){
            if(v[n/2] == v[n/2 + 1]) ans++;
        }
        for(int i=1;i<=(n-1)/2;i++){
            //if i == 5 => 2, if i == 6 => 2
            int opt1 = (v[i] == v[i+1] ? 1 : 0) + (v[n-i+1] == v[n-i] ? 1 : 0);
            int opt2 = (v[n-i+1] == v[i+1] ? 1 : 0) + (v[i] == v[n-i] ? 1 : 0);
            ans += min(opt1, opt2);
        }
        cout << ans << "\n";
    }
}
