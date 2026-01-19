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
    priority_queue<int> pq;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    for(int i=1;i<=m;i++){
        auto u = pq.top();
        pq.pop();
        pq.push(u/2);
    }
    ll ans = 0;
    while(pq.size()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans << "\n";
}
