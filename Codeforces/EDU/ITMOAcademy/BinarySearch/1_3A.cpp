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
    int n;
    cin >> n;
    vector<pair<double,double>> v;
    for(int i=0;i<n;i++){
        double a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    double lo = 0, hi = 2e9+1, mid;
    while((hi-lo)/lo > EPS && (hi-lo) > EPS){
        mid = (hi+lo)/2;
        double l = -2e18+1, r = 2e18+1;
        for(int i=0;i<n;i++){
            l = max(l, v[i].first - v[i].second*mid);
            r = min(r, v[i].first + v[i].second*mid);
        }
        if(r > l) hi = mid;
        else lo = mid;
    }
    cout << setprecision(10) << fixed << lo;
}
