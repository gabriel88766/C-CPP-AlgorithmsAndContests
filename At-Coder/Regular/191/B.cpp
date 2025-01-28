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
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        int msb = 31 - __builtin_clz(n);
        int ans = n;
        k--;
        int p = 0;
        for(int i=0;i<msb;i++){
            if(!(n & (1 << i))){
                if(k & (1 << p)){
                    ans |= (1 << i);
                }
                p++;
                cnt++;
            }
        }
        if(k < (1 << cnt)){
            cout << ans << "\n";
        }else cout << "-1\n";
    }
}
