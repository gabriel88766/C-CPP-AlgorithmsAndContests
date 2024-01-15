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
    ll sx, sy;
    cin >> sx >> sy;
    vector<pair<ll, ll>> vp(n);
    for(int i=0;i<n;i++) cin >> vp[i].first >> vp[i].second;
    double ans = 0;
    for(auto [x, y] : vp){
        ll dx = abs(x - sx);
        ll dy = abs(y - sy);
        ans += 2*sqrt(dx*dx + dy*dy);
    }
    cout << fixed << setprecision(15);
    if(k == 1){
        cout << ans << "\n";
        return 0;
    }
    vector<double> difs(n);
    double sum = 0;
    for(int i=1;i<n;i++){
        ll dx1 = abs(vp[i].first - sx);
        ll dy1 = abs(vp[i].second - sy);
        ll dx2 = abs(vp[i-1].first - sx);
        ll dy2 = abs(vp[i-1].second - sy);
        ll dx3 = abs(vp[i].first - vp[i-1].first);
        ll dy3 = abs(vp[i].second - vp[i-1].second);
        double d = sqrt(dx1*dx1 + dy1*dy1) + sqrt(dx2*dx2+dy2*dy2) - sqrt(dx3*dx3 + dy3*dy3);
        difs[i] = d; 
        sum += d;
    }
    deque<pair<double, int>> minq;
    minq.push_back({0.0, 0});
    for(int i=1;i<n;i++){
        double cur = minq.back().first - difs[i];
        while(minq.size() && cur > minq[0].first) minq.pop_front();
        minq.push_front({cur, i});
        if(i-minq.back().second == k) minq.pop_back();
    }
    ans -= sum;
    ans -= minq.back().first;
    cout << ans << "\n";
}
