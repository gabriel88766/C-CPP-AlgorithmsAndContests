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
    vector<vector<int>> a(3, vector<int>(3));
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin >> a[i][j];
    bool ok = true;
    for(int i=0;i<2;i++){
        int maxv = -INF_INT, minv = INF_INT;
        for(int j=0;j<3;j++){
            int cur = a[i+1][j] - a[i][j];
            minv = min(minv, cur);
            maxv = max(maxv, cur);
        }
        if(maxv != minv) ok = false;
        maxv = -INF_INT, minv = INF_INT;
        for(int j=0;j<3;j++){
            int cur = a[j][i+1] - a[j][i];
            minv = min(minv, cur);
            maxv = max(maxv, cur);
        }
        if(minv != maxv) ok = false;
    }

    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
