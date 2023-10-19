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
        int ans = 0;
        bool ok = true;
        for(int i=n-1;i>=1;i--){
            while(v[i] >= v[i+1] && v[i] != 0){
                v[i] /= 2;
                ans++;
            }
            if(v[i] == 0 && v[i+1] == 0){
                ok = false;
                break;
            }
        }
        if(ok) cout << ans << "\n";
        else cout << "-1\n";
    }
}
