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
        string s;
        cin >> n >> s;
        auto getmin = [&](){
            int mna = -1, mxa = -1, qnta = 0;
            for(int i=0;i<s.size();i++){
                if(s[i] == 'a'){
                    mxa = i;
                    if(mna == -1) mna = i;
                    qnta++;
                }
            }
            if(mna == mxa) return 0LL;
            ll ans = 0;
            int cur = 0;
            for(int i=mna;i<=mxa;i++){
                if(s[i] == 'a') cur++;
                else ans += min(cur, qnta - cur);
            }
            return ans;
        };
        ll ans = getmin();
        for(auto &a : s){
            if(a == 'b') a = 'a';
            else a = 'b';
        }
        ans = min(ans, getmin());
        cout << ans << "\n";
    }
}
