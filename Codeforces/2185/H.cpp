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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n+1), ps(n+1);
        vector<int> ch = {0};
        for(int i=1;i<=n;i++){
            cin >> a[i];
            ps[i] = a[i] + ps[i-1];
            if(a[i] > ps[i-1]) ch.push_back(i);
        }
        ch.push_back(n+1);
        assert(ch.size() < 40);
        auto qr = [&](int r, int j){
            ll ans = ps[r];
            if(r >= j) ans -= a[j];
            return ans;
        };
        
        // auto rch = ch;
        // reverse(ch.begin(), ch.end());
        for(int i=1;i<=n;i++){
            int jx = 0;
            for(int jmp = n; jmp >= 1; jmp >>= 1){
                while(jx + jmp <= n && qr(jx+jmp, i) < a[i]) jx += jmp;
            }
            jx++;
            vector<pair<int, int>> itv;
            for(int j=1;j<ch.size();j++){
                if(jx >= ch[j-1] && jx <= ch[j]){
                    if(jx != ch[j-1]) itv.push_back({ch[j-1], jx-1});
                    if(jx != ch[j]) itv.push_back({jx, ch[j] - 1});
                }else itv.push_back({ch[j-1], ch[j]-1});
            }
            int ans = 0;
            for(auto [ax, bx] : itv){
                int x = 0;
                if(qr(ax, i) >= a[i]) x++;
                for(auto y : ch){
                    if(y == 0) continue;
                    if(y == n+1) continue;
                    if(y > ax && qr(y-1, i) + a[i] < a[y]) x++;
                }
                if(x <= k) ans += bx-ax+1;
            }
            //try i
            int x = 0;
            if(qr(i, i) >= a[i]) x++;
            // cout << x << " - ";
            for(auto y : ch){
                if(y > i && y != n+1) x++;
            }
            if(x <= k) ans--;
            cout << ans << " ";
        }
        cout << "\n";
    }
}       
