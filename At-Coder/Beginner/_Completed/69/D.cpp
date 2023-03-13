#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ans[101][101];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(k+1);
    for(int i=1;i<=k;i++) cin >> v[i];

    int bp = 1, cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int efj;
            if(i%2) efj = j;
            else efj = m+1-j;
            if(cnt+1 > v[bp]){
                bp++;
                cnt = 0;
            }
            cnt++;
            ans[i][efj] = bp;
        }
    }

    for(int i=1;i<=n;i++ ) for(int j=1;j<=m;j++) cout << ans[i][j] << " \n"[j==m];
}
