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
    //freo  pen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k, q;
        cin >> n >> k >> q;
        vector<ll> a(k+1), b(k+1);
        for(int i=1;i<=k;i++) cin >> a[i];
        for(int i=1;i<=k;i++) cin >> b[i];
        for(int i=0;i<q;i++){
            ll d;
            cin >> d;
            if(d == 0){
                cout << "0 ";
                continue;
            }
            auto ind = lower_bound(a.begin(), a.end(), d) - a.begin() - 1;
            ll dx = a[ind+1] - a[ind];
            ll dt = b[ind+1] - b[ind];
            ll ans = b[ind] + (dt* (d - a[ind]))/dx;
            cout << ans << " ";
        }
        cout << "\n";
    }
}
