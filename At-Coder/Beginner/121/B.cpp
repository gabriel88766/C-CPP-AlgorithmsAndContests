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
    int n, m, c;
    cin >> n >> m >> c;
    int ans = 0;
    vector<int> b(m);
    for(int i=0;i<m;i++) cin >> b[i];
    for(int i=0;i<n;i++){
        int cur = c;
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            cur += x * b[j];
        }
        if(cur > 0) ans++;
    }
    cout << ans << "\n";
}
