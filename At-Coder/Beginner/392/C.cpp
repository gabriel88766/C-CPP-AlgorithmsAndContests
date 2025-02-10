#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
int ans[N];
int p[N], q[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
    for(int i=1;i<=n;i++){
        cin >> q[i];
    }
    for(int i=1;i<=n;i++){
        ans[q[i]] = q[p[i]];
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
