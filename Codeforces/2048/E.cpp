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
        if(2*n <= m) cout << "NO\n";
        else{
            cout << "YES\n";
            vector<int> ans;
            for(int i=1;i<=n;i++){
                ans.push_back(i);
                ans.push_back(i);
            }
            for(int i=0;i<2*n;i++){
                int p = i;
                for(int j=0;j<m;j++){
                    cout << ans[p] << " ";
                    p++;
                    if(p == 2*n) p = 0;
                }
                cout << "\n";
            }
        }
    }
}
