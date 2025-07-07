#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-7; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //Approach
    //ternary search
    //check all pairs to be in the circle, by mediatrix
    double ans = 1e18;
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double px = vp[i].first + vp[j].first;
            double py = vp[i].second + vp[j].second;
            px /= 2;
            py /= 2;
            double dx = vp[i].first - vp[j].first;
            double dy = vp[i].second - vp[j].second;
            swap(dx, dy);
            dx = -dx;
            double lo = -1000, hi = 1000;
            auto getdist = [&](double ax, double ay){
                double dist = 0;
                for(int u=0;u<n;u++){
                    dist = max(dist, sqrt(pow(vp[u].first - ax, 2) + pow(vp[u].second - ay, 2)));
                }
                return dist;
            };
            while((hi - lo) > EPS){
                double m1 = lo + (hi - lo)/3;
                double m2 = m1 + (hi - lo)/3;
                double d1 = getdist(px + m1 * dx, py + m1 * dy);
                double d2 = getdist(px + m2 * dx, py + m2 * dy);
                if(d1 < d2) hi = m2;
                else lo = m1;
            }
            ans = min(ans, getdist(px + lo * dx, py + lo * dy));
        }
    }
    cout << fixed << setprecision(8) << ans << "\n";
}
