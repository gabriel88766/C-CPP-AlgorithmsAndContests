#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5 + 3;
ll d[N];
tuple<int, int, int> edg[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    memset(d, 63, sizeof(d));
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edg[i] = {a, b, c};
    }
    d[1] = 0;
    for(int i=1;i<=k;i++){
        int x;
        cin >> x;
        auto [a, b, c] = edg[x];
        if(d[b] > d[a] + c) d[b] = d[a] + c;
    }
    if(d[n] != INF_LL) cout << d[n] << "\n";
    else cout << "-1\n";

}
