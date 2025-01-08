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
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i=0;i<m;i++) cin >> v[i];
    v.resize(unique(v.begin(), v.end()) - v.begin());
    vector<ll> ans(n+2, 0);
    for(int i=1;i<v.size();i++){
        int x1 = v[i-1], x2 = v[i];
        if(x1 > x2) swap(x1, x2);
        //there are 5 cases
        // [1, x1-1] -> then |x2-x1|
        // x1 -> then x2 - 1
        // [x1+1, x2-1] -> then |x2-x1-1|
        // x2 -> then x1
        // [x2+1, n] -> then |x2 - x1|
        ans[1] += x2 - x1;
        ans[x1] -= x2 - x1;
        ans[x1] += x2 - 1;
        ans[x1 + 1] -= x2 - 1;
        ans[x1 + 1] += x2 - x1 - 1;
        ans[x2] -= x2 - x1 - 1;
        ans[x2] += x1;
        ans[x2 + 1] -= x1;
        ans[x2 + 1] += x2 - x1;
    }
    for(int i=1;i<=n;i++){
        ans[i] += ans[i-1];
        cout << ans[i] << " ";
    }
    cout << "\n";
}
