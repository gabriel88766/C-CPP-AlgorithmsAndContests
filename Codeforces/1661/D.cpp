#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll v[300005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> v[i];
    ll ans = 0, curs = 0, curm = 0;
    queue<pair<ll, ll>> qp;
    for(int i=n;i>=1;i--){
        if(v[i] > curs){
            v[i] -= curs;
            int bg = max(i - k + 1, 1);
            ll dif = i - bg + 1;
            ll q = (v[i] + dif - 1) / dif;
            ans += q;
            curm += q;
            curs += q * dif;
            qp.push({bg, q});
        }
        curs -= curm;
        while(!qp.empty() && qp.front().first == i){
            curm -= qp.front().second;
            qp.pop();
        }
    }
    cout << ans << "\n";
}
