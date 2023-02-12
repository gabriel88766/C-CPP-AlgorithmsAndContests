#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    map<int,int> maxe;
    int n, ans = 1;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        maxe[v[i]] = i;
    }
    int bp = 1;
    while(bp <= n){
        int curmax = maxe[v[bp]];
        while(bp < curmax) curmax = max(curmax, maxe[v[bp++]]);
        bp++;
        if(bp <= n) ans = (ans * 2) % MOD;
    }
    cout << ans;
}
