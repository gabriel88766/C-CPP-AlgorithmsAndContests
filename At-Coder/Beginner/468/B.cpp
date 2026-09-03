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
    int m, d;
    cin >> m >> d;
    string s;
    cin >> s;
    s = " " + s;
    int ans = 0;
    for(int i=1;i<=m;i++){
        bool ok = true;
        for(int j = -d; j <= d; j++){
            if(i + j >= 1 && i + j <= m && s[i + j] == 'G') ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << "\n";
}
