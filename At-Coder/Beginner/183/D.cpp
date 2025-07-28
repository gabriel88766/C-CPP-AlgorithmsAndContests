#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll use[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, w;
    cin >> n >> w;
    for(int i=1;i<=n;i++){
        int s, t, p;
        cin >> s >> t >> p;
        use[s] += p;
        use[t] -= p;
    }
    bool ok = true;
    if(use[0] > w) ok = false;
    for(int i=1;i<N;i++){
        use[i] += use[i-1];
        if(use[i] > w) ok = false;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";

}
