#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+1;
int ps[N][26][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        s = " " + s;
        // for(int i=0;i<26;i++) ps[0][i] = 0; //always
        for(int i=1;i<=n;i++){
            for(int k=0;k<2;k++) for(int j=0;j<26;j++) ps[i][j][k] = ps[i-1][j][k];
            ps[i][s[i]-'a'][i%2]++;
        }
        int ans = n;
        
                //no delete
        if(!(n % 2)){
            int cur = n;
            //  - ps[n][i][0] - ps[n][j][1];
            int mv = 0;
            for(int i=0;i<26;i++){
                mv = max(mv, ps[n][i][0]);
            }
            cur -= mv;
            mv = 0;
            for(int i=0;i<26;i++){
                mv = max(mv, ps[n][i][1]);
            }
            cur -= mv;
            ans = min(ans, cur);
        }else{
            //delete k
            for(int k=1;k<=n;k++){
                int cur = n;
                int mv = 0;
                for(int i=0;i<26;i++){
                    mv = max(mv, (ps[n][i][1] - ps[k][i][1]) + ps[k-1][i][0]);
                }
                cur -= mv;
                mv = 0;
                for(int i=0;i<26;i++){
                    mv = max(mv, (ps[n][i][0] - ps[k][i][0]) + ps[k-1][i][1]);
                }
                cur -= mv;
                ans = min(ans, cur);
            }
        }
            
        
        cout << ans << "\n";
    }
}
