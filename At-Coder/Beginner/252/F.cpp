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
    ll S = 0, L;
    int n;
    cin >> n >> L;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i=1;i<=n;i++){
        ll x;
        cin >> x;
        pq.push(x);
        S += x;
    }
    if(S != L) pq.push(L - S);
    ll ans = 0;
    while(pq.size() != 1){
        auto u = pq.top();
        pq.pop();
        auto v = pq.top();
        pq.pop();
        ans += u + v;
        pq.push(u + v);
    }
    cout << ans << "\n";
}
