//Prefix and suffix seg tree.
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int x, n;
    cin >> x >> n;
    ll ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        pq.push(aux);
    }
    while(pq.size() >= 2){
        ll a = pq.top();
        pq.pop();
        a += pq.top();
        pq.pop();
        pq.push(a);
        ans += a;
    }
    cout << ans;
}
