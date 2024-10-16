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
        ll n, x;
        cin >> n >> x;
        vector<ll> b(n);
        for(int i=0;i<n;i++) cin >> b[i];
        sort(b.begin(), b.end()); //just to be sure
        ll lo = 0, hi = 1e9;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            ll l = -2e9, r = 2e9;
            bool ok = true;
            for(int i=0;i<n;i++){
                ll nl = b[i] - mid, nr = b[i] + mid;
                nl = max(l, nl);//cant be lower
                nr = min(nr, r + x);
                if(nr < nl){
                    ok = false; break;
                }else{
                    l = nl;
                    r = nr;
                }
            }
            if(ok) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
        ll l = -2e9, r = 2e9;
        for(int i=0;i<n;i++){
            ll nl = b[i] - lo, nr = b[i] + lo;
            nl = max(l, nl);//cant be lower
            nr = min(nr, r + x);
            if(nr < nl){
                assert(false);
            }else{
                l = nl;
                r = nr;
                cout << r << " ";
            }
        }
        cout << "\n";
    }
}
