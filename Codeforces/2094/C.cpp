#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 805;
int ans[2*N], used[2*N];
int gr[N][N];
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
        for(int i=1;i<=2*n;i++) used[i] = 0; 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> gr[i][j];
                ans[i+j] = gr[i][j];
            }
        }
        for(int i=2;i<=2*n;i++) used[ans[i]] = 1;
        for(int i=1;i<=2*n;i++){
            if(!used[i]){
                ans[1] = i;
            }
        }
        for(int i=1;i<=2*n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
