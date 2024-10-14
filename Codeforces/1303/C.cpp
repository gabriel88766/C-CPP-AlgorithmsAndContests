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
        string s;
        cin >> s;
        string keyb;
        int cur = 0;
        keyb += s[0];
        bool ok = true;
        vector<bool> used(26, false);
        used[s[0]-'a'] = true;
        for(int i=1;i<s.size();i++){
            int l = s[i] - 'a';
            if(!used[l]){
                used[l] = true;
                if(cur == 0){
                    keyb = s[i] + keyb;
                }else if(cur == keyb.size() - 1){
                    cur++;
                    keyb += s[i];
                }else{
                    ok = false;
                    break;
                }
            }else{
                if(keyb[cur] == s[i]);//do nothing
                else if(cur - 1 >= 0 && keyb[cur-1] == s[i]) cur--;
                else if(cur + 1 < keyb.size() && keyb[cur+1] == s[i]) cur++;
                else{
                    ok = false;
                    break;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(!used[i]){
                keyb += (char)('a' + i);
            }
        }
        if(ok) cout << "YES\n" << keyb << "\n";
        else cout << "NO\n";
    }
}
