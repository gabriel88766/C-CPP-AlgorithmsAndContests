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
        int n, d;
        cin >> n >> d;
        vector<int> v(n+1);
        ll sn = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            sn += v[i];
        }
        sn /= n;
        int p = 1;
        int mxd = 0;
        for(int i=1;i<=n;i++){
            ll cn = sn;
            while(p <= n && cn){
                if(v[p] == 0){
                    p++;
                    continue;
                }
                if(v[p] >= cn){
                    v[p] -= cn;
                    cn = 0;
                }else{
                    cn -= v[p];
                    v[p] = 0;
                }
                mxd = max(mxd, abs(p - i));
            }
        }
        cout << (mxd + d - 1) / d << "\n";
    }
}
