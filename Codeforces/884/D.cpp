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
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    while(pq.size() >= 2){
        if(pq.size() % 2){
            ll u = pq.top();
            pq.pop();
            ll v = pq.top();
            pq.pop();
            ll w = pq.top();
            pq.pop();
            u += v + w;
            ans += u;
            pq.push(u);
        }else{
            pq.push(0);
        }
    }
    cout << ans << "\n";
}
