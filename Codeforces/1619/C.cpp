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
        string a, s, b;
        cin >> a >> s;
        reverse(a.begin(), a.end());
        reverse(s.begin(), s.end());
        int p = 0;
        bool ok = true;
        for(int i = 0;i<a.size(); i++){
            if(p == s.size()){
                ok = false;
                break;
            }
            if(a[i] <= s[p]){
                b += '0' + s[p] - a[i];
                p++;
            }else{
                b += '0' + 10 + s[p] - a[i];
                p++;
                if(p == s.size() || s[p] != '1'){
                    ok = false;
                    break;
                }
                p++;
            }
        }
        if(ok){
            while(p < s.size()){
                b += s[p++];
            }
            reverse(b.begin(), b.end());
            int fn0 = 0;
            for(int i=0;i<b.size()-1;i++){
                if(b[fn0] == '0') fn0++;
            }
            cout << b.substr(fn0, b.size()-fn0) << "\n";
        }else cout  << "-1\n";
        
        
    }
}
