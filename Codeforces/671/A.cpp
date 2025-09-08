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
    ll ax, ay, bx, by, tx, ty, n;
    cin >> ax >> ay >> bx >> by >> tx >> ty >> n;
    double ans = 0;
    vector<pair<ll, ll>> vp(n);
    vector<pair<double, int>> dst1, dst2;
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
        double cur = 2 * sqrt(pow(vp[i].first - tx, 2) + pow(vp[i].second - ty, 2));
        ans += cur;
        double p1 = sqrt(pow(vp[i].first - tx, 2) + pow(vp[i].second - ty, 2)) + sqrt(pow(vp[i].first - ax, 2) + pow(vp[i].second - ay, 2));
        double p2 = sqrt(pow(vp[i].first - tx, 2) + pow(vp[i].second - ty, 2)) + sqrt(pow(vp[i].first - bx, 2) + pow(vp[i].second - by, 2));
        dst1.push_back({p1 - cur, i});
        dst2.push_back({p2 - cur, i});
    }
    sort(dst1.begin(), dst1.end());
    sort(dst2.begin(), dst2.end());
    if(dst1[0].second != dst2[0].second){
        double bst = min({dst1[0].first + dst2[0].first, dst1[0].first, dst2[0].first});
        ans += bst;
    }else if(n >= 2){
        double bst = min({dst1[0].first + dst2[1].first, dst1[1].first + dst2[0].first, dst1[0].first, dst2[0].first});
        ans += bst;
    }else{
        ans += min({dst1[0].first, dst2[0].first});
    }
    cout << fixed << setprecision(20) << ans << "\n";
}
