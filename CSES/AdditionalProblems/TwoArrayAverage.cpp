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
    double lo = 1, hi = 1'000'000'000;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int j=0;j<n;j++) cin >> b[j];
    while(((hi-lo)/lo > EPS) && (hi - lo) > EPS){
        double mid = (lo + hi)/2;
        double cs = 0, g1 = -1e30, g2 = -1e30;
        for(int j=0;j<n;j++){
            cs += a[j] - mid;
            g1 = max(g1, cs);
        }
        cs = 0;
        for(int j=0;j<n;j++){
            cs += b[j] - mid;
            g2 = max(g2, cs);
        }
        if(g1 + g2 >= 0) lo = mid;
        else hi = mid;
    }
    double cs = 0, g1 = -1e30, g2 = -1e30;
    int i1 = -1, i2 = -1;
    for(int j=0;j<n;j++){
        cs += a[j] - lo;
        if(cs > g1){
            g1 = cs;
            i1 = j;
        }
    }
    cs = 0;
    for(int j=0;j<n;j++){
        cs += b[j] - lo;
        if(cs > g2){
            g2 = cs;
            i2 = j;
        }
    }
    cout << i1+1 << " " << i2+1 << "\n";
    // cout << lo << "\n";
}
