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
    int n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<int> v = {(int)x};
    while(v.size() < n){
        x = a*x + b;
        x %= c;
        v.push_back(x);
    }
    int ans = 0;
    deque<pair<int, int>> dq;
    for(int i=0;i<n;i++){
        while(dq.size() && dq.back().first >= v[i]) dq.pop_back();
        dq.push_back({v[i], i});
        if(i >= k-1){
            ans ^= dq.front().first;
            // sum -= v[i-k+1];
            if(dq.size() && dq.front().second == i - k + 1) dq.pop_front();
        }
    }
    cout << ans << "\n";
}
