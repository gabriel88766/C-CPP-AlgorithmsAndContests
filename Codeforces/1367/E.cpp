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
        string s;
        cin >> s;
        vector<int> cnt(26, 0);
        for(auto c : s) cnt[c-'a']++;
        int ans = 1;
        for(int i=2;i<=n;i++){
            vector<bool> us(i, false);
            int ov = 0, cur = 0;
            while(!us[ov]){
                us[ov] = true;
                cur++;
                ov = (ov + k) % i;
            }
            int need = i / cur, ok = 0;
            for(int j=0;j<26;j++){
                ok+= cnt[j]/cur;
            }
            if(ok >= need) ans = i;
        }
        cout << ans << "\n";
    }
}
