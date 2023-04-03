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
        int q;
        cin >> q;
        ll hmin = -1, hmax = INF_LL;
        while(q--){
            int ev;
            cin >> ev;
            if(ev == 1){
                ll curmin, curmax;
                ll a, b, n;
                cin >> a >> b >> n;
                if(n == 1){
                    curmin = 1;
                    curmax = a;
                }else{
                    curmin = a*(n-1) - b*(n-2) + 1;
                    curmax = a*n - b*(n-1);
                }
                if((curmin >= hmin && curmin <= hmax) || (curmax <= hmax && curmax >= hmin) || (curmin < hmin && curmax > hmax)){
                    cout << "1 ";
                    hmin = max(curmin,hmin), hmax = min(curmax,hmax);
                }else cout << "0 ";
            }else{
                ll a, b;
                cin >> a >> b;
                if(hmin == -1) cout << "-1 ";
                else{
                    ll nmin, nmax;
                    ll cl = a-b;
                    nmin = ( hmin <= a ? 1 : (hmin-a-1)/cl+2);
                    nmax = (hmax <= a ? 1 : (hmax-a-1)/cl+2);
                    if(nmin == nmax) cout << nmax << " ";
                    else cout << "-1 "; 
                }
            }
        }
        cout << "\n";
    }
}       
