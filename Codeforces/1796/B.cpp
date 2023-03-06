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
    int T;
    cin >> T;
    while(T--){
        string s, t, ans;
        cin >> s >> t;
        if(s[0] == t[0]){
            cout << "YES\n";
            cout << s[0] << "*" << "\n";
        }else if(s[s.size()-1] == t[t.size()-1]){
            cout << "YES\n";
            cout << "*" << t[t.size()-1] << "\n";
        }else{
            bool ok = false;
            for(int i=1;i<s.size();i++){
                for(int j=1;j<t.size();j++){
                    if(ok) break;
                    if(s.substr(i-1, 2) == t.substr(j-1, 2)){
                        cout << "YES\n";
                        cout << "*" << s.substr(i-1,2) << "*" << "\n";
                        ok = true;
                    }
                }
            }
            if(!ok) cout << "NO\n";
        }
    }
}
