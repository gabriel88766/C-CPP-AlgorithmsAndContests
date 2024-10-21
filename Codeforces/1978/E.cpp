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
        string s1, s2;
        cin >> n >> s1 >> s2;
        s1 = " " + s1;
        s2 = " " + s2;
        vector<int> ps1(n+1), ps2(n+1);
        for(int i=1;i<=n;i++){
            if(s1[i] == '1') ps1[i]++;
            ps1[i] += ps1[i-1];
        }
        function<bool(int, int, int)> check = [&](int l, int r, int u){
            if(s1[u] == '1') return false; //cant make the sum greater
            bool ok1 = false, ok2 = false;
            if(u-2 >= l && s1[u-2] == '0' && s1[u] == '0') ok1 = true;
            if(u+2 <= r && s1[u] == '0' && s1[u+2] == '0') ok2 = true;
            if(u-1 >= l && s2[u-1] == '1') ok1 = true;
            if(u+1 <= r && s2[u+1] == '1') ok2 = true;
            if(ok1 && ok2) return true;
            else return false;
        };
        for(int i=2;i<=n-1;i++){
            //check if I can modify
            ps2[i] = ps2[i-1];
            if(check(1, n, i)) ps2[i]++;
        }
        int q;
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            if(r - l >= 5){
                int ans = ps1[r] - ps1[l-1];
                for(int j=l;j<=l+1;j++) ans += check(l, r, j);
                for(int j=r-1;j<=r;j++) ans += check(l, r, j);
                ans += ps2[r-2] - ps2[l+1];
                cout << ans << "\n";
            }else{
                //check it all
                int ans = ps1[r] - ps1[l-1];
                for(int j=l;j<=r;j++) ans += check(l, r, j);
                cout << ans << "\n";
            }
        }
    }
}
