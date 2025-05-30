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
        bool ok = true;
        int n;
        cin >> n;
        vector<int> v(n+2, 1);
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<=n;i++){
            if(v[i] == 0){
                if(v[i-1] != 1 || v[i+1] != 1) ok = false;
            }
        }
        bool ok2 = false;
        for(int i=1;i<=n;i++){
            if(v[i] == 0) ok2 = true;
        }
        if(!ok2) ok = false;
        if(ok) cout << "NO\n";
        else cout << "YES\n";
    }
}
