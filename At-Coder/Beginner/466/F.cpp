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
    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        vector<ll> xn;
        xn.push_back(x+1);
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ll m;
            cin >> m;
            if(xn.back() > m) xn.push_back(m);
        }
        priority_queue<pair<ll, ll>> pq;
        pq.push({xn[0] - 1, 1});
        for(int i=1;i<xn.size();i++){
            ll nt = 0;
            while(pq.size() && pq.top().first >= xn[i]){
                nt += (pq.top().first / xn[i]) * pq.top().second;
                ll r = pq.top().first % xn[i];
                pq.push({r, pq.top().second});
                pq.pop();
            }
            pq.push({xn[i] - 1, nt});
        }
        while(pq.size()){
            ans += pq.top().second;
            pq.pop();
        }
        ans--;
        cout << ans << "\n";
    }
}
