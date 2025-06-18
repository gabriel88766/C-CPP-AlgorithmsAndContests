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
        int n, s;
        cin >> n >> s;
        int mn = INF_INT, mx = -INF_INT;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        if(s >= mn && s <= mx) cout << mx - mn + min(s - mn, mx - s) << "\n";
        else if(s < mn) cout << mx - s << "\n";
        else if(s > mx) cout << s - mn << "\n";
        else assert(false);
    }
}
