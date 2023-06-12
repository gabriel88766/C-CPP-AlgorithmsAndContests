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
    int ans = 0;
    int n, m;
    cin >> n;
    vector<string> u(n);
    for(int i=0;i<n;i++) cin >> u[i];
    cin >> m;
    vector<string> v(m);
    for(int i=0;i<m;i++) cin >> v[i];
    for(int i=0;i<n;i++){
        int cur = 0;
        for(int j=0;j<n;j++){
            if(u[j] == u[i]) cur++;
        }
        for(int j=0;j<m;j++){
            if(v[j] == u[i]) cur--;
        }
        ans = max(ans, cur);
    }
    cout << ans;
}
