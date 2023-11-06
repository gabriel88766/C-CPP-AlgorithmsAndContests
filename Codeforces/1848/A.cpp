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
        int n, m, k, a, b;
        cin >> n >> m >> k >> a >> b;
        bool ok = true;
        for(int i=0;i<k;i++){
            int c, d;
            cin >> c >> d;
            int s1 = c+d;
            int s2 = a+b;
            if(s1%2 == s2%2) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
