#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll pt[50];
ll maxn = 1e18;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    pt[0] = 1;
    int mv;
    for(int i=1;i<50;i++){
        pt[i] = 3 * pt[i-1];
        if(pt[i] >= maxn) break;
        else mv = i;
    }
    while(t--){
        ll a, b;
        cin >> b >> a;
        if(a % 2 == b % 2){
            for(int i=mv;i>=0;i--){
                ll lo = 0, hi = b/pt[i];
                while(lo != hi){
                    ll mid = lo + (hi-lo+1)/2;
                    if((b - pt[i]*mid) >= (a - mid)) lo = mid;
                    else hi = mid - 1;
                }
                b -= pt[i] * lo;
                a -= lo;
            }
            if(a == 0 && b == 0) cout << "Yes\n";
            else cout << "No\n";
        }
        else cout << "No\n";
    }
}
