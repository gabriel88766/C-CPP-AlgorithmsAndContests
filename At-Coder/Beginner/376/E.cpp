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
        int n, k;
        cin >> n >> k;
        vector<pair<ll,ll>> vp(n+1);
        for(int i=1;i<=n;i++) cin >> vp[i].first;
        for(int i=1;i<=n;i++) cin >> vp[i].second;
        sort(vp.begin(), vp.end());
        ll sum = 0, ans = INF_LL;
        priority_queue<ll> pq;
        for(int i=1;i<=n;i++){//keep sum of k smallest.
            sum += vp[i].second;
            pq.push(vp[i].second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(i >= k) ans = min(ans, sum * vp[i].first);
        }
        cout << ans << "\n";
    }
}
