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
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = " " + s;
    vector<int> ok(n+1, 0);
    int ans = 0;
    for(int i=1;i<=n-2;i++){
        if(s.substr(i, 3) == "ABC"){
            ok[i] = 1;
            ans++;
        }
    }
    for(int i=0;i<q;i++){
        int j;
        char c;
        cin >> j >> c;
        s[j] = c;
        for(int k=max(j-2, 1); k <= min(j, n-2); k++){
            int st = (s.substr(k, 3) == "ABC" ? 1 : 0);
            ans += st - ok[k];
            ok[k] = st;
        }
        cout << ans << "\n";
    }
}
