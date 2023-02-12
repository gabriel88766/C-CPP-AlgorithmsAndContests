#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    vector<int> rv(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++){
        int cur = 0;
        for(int j=0;j<k;j++){
            if(v[i][k-j-1] == '1') cur += (1 << j);
        }
        rv[i] = cur;
    } 
    int ans = 31;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans = min(ans, __builtin_popcount(rv[i]^rv[j]));
        }
    }
    cout << ans;
}
