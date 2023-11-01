#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    set<int> xors;
    xors.insert(0);
    int cur = 0;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        cur ^= aux;
        xors.insert(cur);
    }
    int best = *prev(xors.end());
    if(best == 0 || best == 1) cout << best << "\n";
    else{
        set<int> g1, g2;
        for(auto x : xors){
            if(__builtin_clz(x) == __builtin_clz(best)) g1.insert(x);
            else g2.insert(x);
        }
        //the best is something join the first with second. Bin search bit-bit
        int fb = 30;
        while(!((1 << fb) & best)) fb--;
        int lg = 0, rg = (1 << fb) - 1;
        int ans = 0;
        for(auto x : g1){
            int l = lg, r = rg;
            for(int i=fb-1;i>=0;i--){
                if(x & (1 << i)){
                    auto it = g2.lower_bound(l);
                    if(it != g2.end() && *it <= (r - (1 << i))) r -= (1 << i);
                    else l += (1 << i);
                }else{
                    auto it = g2.lower_bound(l + (1 << i));
                    if(it != g2.end() && *it <= r) l += (1 << i);
                    else r -= (1 << i);
                }
            }
            ans = max(ans, x^l);
        }
        cout << ans << "\n";
    }
}
