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
        int h, w;
        string s;
        cin >> h >> w >> s;
        int cd = 0, cr = 0, cqm = 0;
        for(auto &c : s){
            if(c == 'D') cd++;
            if(c == 'R') cr++;
            if(c == '?') cqm++;
        }
        ll ans = 1;
        int dl = 0, rl = 0, qm = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'D'){
                dl++;
                cd--;
            }else if(s[i] == 'R'){
                cr--;
                rl++;
            }else{
                cqm--;
                qm++;
            }
            int mxd = min(qm, h-1-cd-dl);
            int mnd = 0;
            if(qm + cr + rl > w - 1) mnd = qm + cr + rl - w + 1;
            ans += mxd-mnd + 1;
        }
        cout << ans << "\n";
    }
}
