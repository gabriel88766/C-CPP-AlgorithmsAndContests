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
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    int ii = 1, jj = n;
    for(int i=2;i<=n;i++){
        if(v[i] > v[ii]) ii = i;
        else break;
    }
    for(int i=n-1;i>=1;i--){
        if(v[i] > v[jj]) jj = i;
        else break;
    }
    assert(jj >= ii);
    if(v[ii] == v[jj]){
        bool ok = true;
        for(int i=ii;i<=jj;i++) if(v[i] != v[ii]) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }else cout << "NO\n";
}
