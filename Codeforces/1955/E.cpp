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
        string s;
        cin >> s;
        int ans = 1;
        for(int i=2;i<=n;i++){
            vector<int> ps(n+1, 0);
            int cur = 0;
            bool ok = true;
            for(int j=0;j<n;j++){
                cur -= ps[j];
                int par = cur;
                if(s[j] == '0') par++;
                if(par % 2){
                    if(j + i <= n){
                        ps[j+i]++;
                        cur++;
                    }else{
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) ans = i;
        }
        cout << ans << "\n";
    }
}
