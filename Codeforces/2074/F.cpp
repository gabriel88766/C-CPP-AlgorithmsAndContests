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
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ll ans = 0;
        vector<int> ax;
        while(l2 < r2){
            int lsb = l2 == 0 ? 30 : __builtin_ctz(l2);
            int jmp = 1 << lsb;
            if(l2 + jmp > r2){
                int msb = 31 - __builtin_clz(l2 ^ r2);
                jmp = (1 << msb);
            }
            l2 += jmp;
            ax.push_back(jmp);
        }
        while(l1 < r1){
            int lsb = l1 == 0 ? 30 : __builtin_ctz(l1);
            int jmp = 1 << lsb;
            if(l1 + jmp > r1){
                int msb = 31 - __builtin_clz(l1 ^ r1);
                jmp = (1 << msb);
            }
            l1 += jmp;
            for(auto &x : ax){
                if(jmp >= x){
                    ll vx = jmp / x;
                    ans += vx;
                }else{
                    ll vx = x / jmp;
                    ans += vx;
                }
            }
        }
        cout << ans << "\n";
    }
}
