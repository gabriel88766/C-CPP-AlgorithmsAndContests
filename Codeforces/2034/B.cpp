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
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        int wk = 0, ans = 0, x = 0;
        for(int i=0;i<n;i++){
            if(x != 0){
                x--;
                continue;
            }
            if(s[i] == '0') wk++;
            else wk = 0;
            if(wk == m){
                wk = 0;
                x = k-1;
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
