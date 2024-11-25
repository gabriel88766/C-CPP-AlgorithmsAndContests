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
    int n, w;
    cin >> n >> w;
    vector<bool> ok(w+1, false);
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++){
        if(v[i] <= w) ok[v[i]] = true;
        for(int j=i+1;j<n;j++){
            if(v[i] + v[j] <= w) ok[v[i] + v[j]] = true;
            for(int k=j+1;k<n;k++){
                if(v[i] + v[j] + v[k] <= w) ok[v[i] + v[j] + v[k]] = true;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=w;i++) if(ok[i]) ans++;
    cout << ans << "\n";
}
