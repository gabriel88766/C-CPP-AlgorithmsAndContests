#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ans[505][505];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> p(n+1), q(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++) cin >> q[i];

    for(int i=1;i<=n;i++){
        int r = p[i];
        for(int j=1;j<=n;j++){
            int c = q[j];
            if(j <= (n-i)) ans[r][c] = 0;
            else ans[r][c] = 1;
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
