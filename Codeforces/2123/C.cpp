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
        vector<int> mn(n), mx(n), v(n);
        int cmn = INF_INT;
        for(int i=0;i<n;i++){
            cin >> v[i];
            cmn = min(v[i], cmn);
            mn[i] = cmn;
        }
        int cmx = 0;
        for(int i=n-1;i>=0;i--){
            cmx = max(v[i], cmx);
            mx[i] = cmx;
        }
        for(int i=0;i<n;i++){
            if(mx[i] == v[i] || mn[i] == v[i]) cout << "1";
            else cout << "0";
        }
        cout << "\n";
    }
}
