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
        int c, m, x;
        cin >> c >> m >> x;
        int lo = 0, hi = min((c+m+x)/3, min(c, m));
        while(lo != hi){
            int mid = lo + (hi - lo + 1)/2;
            //mid <= min(c, m);
            int xx = x + (c-mid) + (m - mid);
            if(xx >= mid) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}
