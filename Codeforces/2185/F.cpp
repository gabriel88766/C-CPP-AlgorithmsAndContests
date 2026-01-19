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
        int n, q;
        cin >> n >> q;
        vector<int> a(1 << n);
        vector<int> ps(1 << n);
        for(int i=0;i<(1 << n);i++){
            cin >> a[i];
            ps[i] = a[i];
            if(i != 0) ps[i] ^= ps[i-1];
        }
        auto qr = [&](int l, int r){
            int ans = ps[r];
            if(l > 0) ans ^= ps[l-1];
            return ans;
        };
        for(int i=1;i<=q;i++){
            int b, c;
            cin >> b >> c;
            --b;
            int ans = 0, cxor = c;
            int umsk = 0;
            for(int j=0;j<n;j++){
                int gs = b & ((~umsk) & ((1 << n)-1));
                gs ^= (1 << j);
                int x2 = qr(gs, gs + (1 << j) - 1);
                if(x2 > cxor){
                    ans += (1 << j);
                }else if(x2 == cxor && gs < b){
                    ans += (1 << j);
                }
                umsk |= (1 << j);
                cxor ^= x2;
            }
            cout << ans << "\n";
        }
    }
}
