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
        int n, m;
        cin >> n >> m;
        vector<string> goal(n);
        vector<vector<string>> as(m, vector<string>(n));
        for(int i=0;i<n;i++) cin >> goal[i];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> as[i][j];
            }
        }
        bool ok = true;
        for(int j=0;j<n;j++){
            bool cok = false;
            for(int i=0;i<m;i++){
                if(as[i][j] == goal[j]) cok = true;
            }
            if(!cok) ok = false;
        }
        int meq = 0;
        for(int i=0;i<m;i++){
            int ceq = 0;
            for(int j=0;j<n;j++){
                if(as[i][j] == goal[j]) ceq++;
            }
            meq = max(meq, ceq);
        }
        if(ok){
            int ans = n + (n - meq) * 2;
            cout << ans << "\n";
        }else cout << "-1\n";
    }
}
