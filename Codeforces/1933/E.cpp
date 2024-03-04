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
        int n;
        cin >> n;
        vector<ll> v(n+1), ps(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            ps[i] = ps[i-1] + v[i];
        }
        int q;
        cin >> q;
        while(q--){
            ll l, u;
            cin >> l >> u;
            int lo = l, hi = n;
            while(lo != hi){
                int mid = lo + (hi - lo + 1)/2;
                if(ps[mid] - ps[l-1] <= u) lo = mid;
                else hi = mid - 1;
            }
            if(lo == n) cout << n << " ";
            else{   
                ll fst = u - (ps[lo] - ps[l-1]);
                ll lst = u - (ps[lo+1] - ps[l-1]) + 1;
                if(abs(lst) < abs(fst)) cout << lo + 1 << " ";
                else cout << lo << " ";
            }
        }
        cout << "\n";
    }
}
 