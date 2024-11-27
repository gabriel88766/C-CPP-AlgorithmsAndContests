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
    string s, t;
    cin >> s >> t;
    bool ok = true;
    while(s.size() || t.size()){
        if(!s.size()){
            ok = false;
            break;
        }else if(!t.size()){
            ok = false;
            break;
        }else{
            if(s.back() != t.back()){
                ok = false;
                break;
            }else{
                int cs = 0, ct = 0;
                char x = s.back();
                while(s.size() && s.back() == x){
                    cs++;
                    s.pop_back();
                }
                while(t.size() && t.back() == x){
                    ct++;
                    t.pop_back();
                }
                if(cs > ct || (cs < ct && cs == 1)){
                    ok = false;
                    break;
                }
            }
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
