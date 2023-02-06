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
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> q;
        vector<ll> qtt(26, 0), qts(26, 0);
        int maxt = 0, maxs =0;
        qts[0] = qtt[0] = 1;
        for(int i=0;i<q;i++){
            int d, k;
            string s;
            cin >> d >> k >> s;
            if(d == 1) {
                for(int j=0;j<s.size();j++){
                    qts[s[j]-'a'] += k;
                    maxs = max(maxs, (int)(s[j] - 'a'));
                }
            }else {
                for(int j=0;j<s.size();j++) {
                    qtt[s[j]-'a'] += k;
                    maxt = max(maxt, (int)(s[j]-'a'));
                }
            }
            bool pos = true;
            for(int j=0;j<26;j++){
                if(qts[j]){
                    if(maxt > j) break;
                    else{
                        if(qts[j] >= qtt[j] ||  maxs > j) pos = false;
                        break;
                    }
                }
            }
            if(pos) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
