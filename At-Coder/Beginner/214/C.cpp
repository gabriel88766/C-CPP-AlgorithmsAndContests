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
    vector<int> s(n), ans(n);
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++) cin >> ans[i];
    
    
    for(int i=1; i < 2*n; i++){
        int curi = i >= n ? i-n : i;
        int lst = (i-1) >= n ? i-n-1 : i-1;
        ans[curi] = min(ans[curi], ans[lst] + s[lst]);
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << "\n";
    }
}
