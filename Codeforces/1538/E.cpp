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
        cin >> n;
        string lv;
        map<string, ll> mp;
        map<string, string> suf, pre;
        while(n--){
            string var, op;
            cin >> var >> op;
            if(op == ":="){
                string s;
                cin >> s;
                suf[var] = pre[var] = s;
                mp[var] = 0;
                if(s.size() >= 4){
                    for(int i=0;i<=s.size()-4;i++){
                        if(s.substr(i, 4) == "haha") mp[var]++;
                    }
                }
            }else{
                //op =
                string var1, var2;
                char c;
                cin >> var1 >> c >> var2;
                ll qt = mp[var1] + mp[var2];
                for(int i=1;i<=3;i++){
                    if(suf[var1].size() >= i && pre[var2].size() >= (4-i)){
                        string s = suf[var1].substr(suf[var1].size()-i, i) + pre[var2].substr(0, 4-i);
                        if(s == "haha") qt++;   
                    }
                }
                if(pre[var1].size() >= 4) pre[var] = pre[var1];
                else pre[var] = pre[var1] + pre[var2];
                if(suf[var2].size() >= 4) suf[var] = suf[var2];
                else suf[var] = suf[var1] + suf[var2];
                mp[var] = qt; 
            }
            if(n == 0) lv = var;
        }
        cout << mp[lv] << "\n";

    }
}
