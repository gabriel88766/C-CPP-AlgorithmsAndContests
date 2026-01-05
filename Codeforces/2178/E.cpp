#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll query(int l, int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    ll ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        function<int(int, int)> solve = [&](int l, int r){
            if(l == r) return l;
            ll sum = query(l, r);
            int lo = l, hi = r;
            while(lo != hi){
                int mid = lo + (hi - lo)/2;
                ll qrs = query(l, mid);
                if(2*qrs == sum){
                    lo = hi = mid;
                }else if(2*qrs > sum){
                    hi = mid;
                }else{
                    lo = mid + 1;
                }
            }
            if(lo - l + 1 >= r - lo) return solve(lo + 1, r);
            else return solve(l, lo);
        };
        int x = solve(1, n);
        ll y = query(x, x);
        cout << "! " << y << "\n";
        cout.flush();
    }

}
