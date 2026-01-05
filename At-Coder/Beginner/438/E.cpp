#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
const int M = 31;
int jmp[N][M];
ll ttw[N][M];
int a[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> jmp[i][0];
        ttw[i][0] = i;
    }
    for(int j=1;j<=30;j++){
        for(int i=1;i<=n;i++){
            jmp[i][j] = jmp[jmp[i][j-1]][j-1];
            ttw[i][j] = ttw[i][j-1] + ttw[jmp[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=q;i++){
        int t,b;
        cin >> t >> b;  
        ll ans = 0;
        for(int j=30;j>=0;j--){
            if(t & (1 << j)){
                ans += ttw[b][j];
                b = jmp[b][j];
            }
        }
        cout << ans << "\n";
    }
}
