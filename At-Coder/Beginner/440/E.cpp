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
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<ll>());
    ll cur = v[0] * k;
    priority_queue<tuple<ll, int, int>> pq;
    pq.push({cur, k, 1});
    while(x--){
        auto [a, b, c] = pq.top();
        pq.pop();
        cout << a << "\n";
        if(b == 0) continue;
        for(int j=c;j<n;j++){
            pq.push({a + v[j] - v[0], b-1, j});
        }
    }


}
