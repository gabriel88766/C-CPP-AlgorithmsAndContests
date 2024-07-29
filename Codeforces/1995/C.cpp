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
        ll ans = 0;
        ll ox = 1, op = 0;
        bool ok = true;
        for(int i=0;i<n;i++){
            // cout << ans << " ";
            ll x;
            cin >> x;
            if(!ok) continue;
            if(x == 1){
                if(ox > 1) ok = false;
                continue;
            }
            if(i == 0 || ox == 1){
                ox = x, op = 0;
                continue;
            }
            if(ox < x){
                while(ox*ox <= x){
                    ox *= ox;
                    op--;
                }
                if(op < 0) op = 0;
                ans += op;
                ox = x;
            }else if(ox == x){
                ans += op;
            }else{
                //ox > x
                ll aux = x;
                //cout << aux << " " << ox << "\n";
                while(aux < ox){
                    aux *= aux;
                    op++;
                }
                ans += op;
                ox = x;
            }
        }
        if(!ok) cout << "-1\n";
        else cout << ans << "\n";
    }
}
