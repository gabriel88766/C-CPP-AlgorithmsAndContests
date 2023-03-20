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
    // t = 1;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        int sa = 0, sb = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(v[i] % 2) sb+= v[i];
            else sa+= v[i];
        }
        if(sa > sb) cout << "YES\n";
        else cout << "NO\n";
    }
}
