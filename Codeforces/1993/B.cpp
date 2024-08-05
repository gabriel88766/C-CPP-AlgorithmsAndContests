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
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int ce = 0;
        for(int i=0;i<n;i++) if(!(a[i] % 2)) ce++;
        if(ce == n || ce == 0) cout << "0\n";
        else{
            //even and odd
            vector<ll> el;
            ll mxo = 0;
            int ans = 0;
            for(int i=0;i<n;i++){
                if(a[i] % 2) mxo = max(mxo, a[i]);
                else el.push_back(a[i]);
            }
            sort(el.begin(), el.end());
            bool ok = true;
            for(auto x : el){
                if(mxo > x) mxo += x;
                else{
                    ok = false;
                    break;
                }
            }
            if(ok) cout << ce << "\n";
            else cout << ce + 1 << "\n";
        }
    }
}
