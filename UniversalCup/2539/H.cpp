#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 405;
ll val[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin >> val[i][j];
            ans += val[i][j];
        }
    }
    priority_queue<tuple<int, int, int>> qp;
    vector<int> cp(n+1, 0);
    for(int i=1;i<=n;i++){
        vector<int> vc;
        for(int j=1;j<=k;j++) vc.push_back(val[j][i]);
        sort(vc.begin(), vc.end());
        for(int j=0;j<k;j++){
            if(j > 0 && vc[j] == vc[j-1]) continue;
            qp.push({k - j, vc[j], i});
        }
    }
    while(qp.size() && m > 0){
        auto [val, mx, j] = qp.top();
        qp.pop();
        ll qnt = mx - cp[j];
        if(m >= qnt){
            m -= qnt;
            ans -= qnt * val;
            cp[j] = mx;
        }else{
            ans -= m * val;
            cp[j] += m;
            m = 0;
        }
    }
    cout << ans << "\n";
}
