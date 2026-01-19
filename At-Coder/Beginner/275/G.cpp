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
    vector<tuple<ll, ll, ll>> vt1, vt2;
    for(int i=0;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a >= b) vt1.push_back({a, b, c});
        else vt2.push_back({a, b, c});
    }
    double lo = 0.09, hi = 10.01;
    while(hi - lo > EPS){
        double mid = (lo + hi) / 2;
        bool ok = false;
        double m1 = 0, m2 = 0;
        for(auto [a, b, c] : vt1){
            double xmn = b * mid;
            double xmx = a * mid;
            if(c >= xmx) ok = true;
            if(c >= xmn){
                //add to possible sums
                m1 = max(m1, (c-xmn)/(xmx-xmn));
            }
        }
        for(auto [a, b, c] : vt2){
            double xmn = a * mid;
            double xmx = b * mid;
            if(c >= xmx) ok = true;
            if(c >= xmn){
                //add to possible sums
                m2 = max(m2, (c-xmn)/(xmx-xmn));
            }
        }
        //additional check
        if(m1 + m2 >= 1) ok = true;
        if(ok) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(10) << lo << "\n";
}
