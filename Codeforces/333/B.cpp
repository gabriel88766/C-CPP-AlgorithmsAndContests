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
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> ban(n+1, vector<bool> (n+1, false));
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        ban[a][b] = true;
    }
    int ans = 0;
    bool cm = false;
    for(int i=2;i<n;i++){
        bool ok = true;
        for(int j=1;j<=n;j++) if(ban[i][j]) ok = false;
        if(n-i == i-1 && ok) cm = true;
        else if(ok) ans++;
    }
    for(int j=2;j<n;j++){
        bool ok = true;
        for(int i=1;i<=n;i++) if(ban[i][j]) ok = false;
        if(n-j == j-1 && ok) cm = true;
        else if(ok) ans++;
    }
    if(cm) ans++;
    cout << ans << "\n";
}
