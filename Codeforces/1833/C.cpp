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
        bool ok = false;

        int lo = INF_INT, le = INF_INT;
        for(int i=0;i<n;i++){
            if(v[i] % 2) lo = min(lo, v[i]);
            else le = min(le, v[i]);
        }
        //all odd
        bool nok = false;
        for(int i=0;i<n;i++){
            if(v[i]%2) continue;
            else{
                //even
                if(lo >= v[i]) nok = true; 
            }
        }
        if(!nok) ok = true;
        //all even
        if(lo == INF_INT) ok = true;

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
