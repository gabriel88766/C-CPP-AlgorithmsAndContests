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
    //freopen("in", "r", stdin); //test input
    string s, t;
    cin >> s >> t;
    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    string old = ans;

    for(int i=s.size();i>=0;i--){
        if(s.size() - i < t.size()) continue;
        bool ok = true;
        for(int j=0;j<t.size();j++){
            if(s[i+j] != '?' && s[i+j] != t[j]) ok = false;
        }
        if(ok){
            string cur = s;
            for(int j=0;j<t.size();j++) cur[i+j] = t[j];
            for(int j=0;j<s.size();j++) if(cur[j] == '?') cur[j] = 'a';
            ans = cur;
            break;
        }
    }



    if(ans == old) cout << "UNRESTORABLE";
    else cout << ans;
}
