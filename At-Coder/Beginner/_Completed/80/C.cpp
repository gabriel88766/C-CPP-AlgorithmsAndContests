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
    int n;
    cin >> n;
    vector<vector<int>> f(n, vector<int> (10));
    vector<vector<int>> p(n, vector<int> (11));
    for(int i=0;i<n;i++) for(int j=0;j<10;j++) cin >> f[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<11;j++) cin >> p[i][j];
    ll maxp = -INF_LL;
    for(int i=1;i<1024;i++){
        ll curp = 0;
        vector<int> op(10, 0);
        for(int j=0;j<10;j++) if(i & (1 << j)) op[j] = 1; 
        for(int j=0;j<n;j++){
            int cnt = 0;
            for(int k=0;k<10;k++) if(op[k] && f[j][k]) cnt++;
            curp += p[j][cnt];
        }
        maxp = max(curp, maxp);
    }
    cout << maxp;
}
