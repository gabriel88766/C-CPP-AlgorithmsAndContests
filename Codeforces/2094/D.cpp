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
        string p, s;
        cin >> p >> s;
        reverse(p.begin(), p.end());
        reverse(s.begin(), s.end());
        bool ok = true;
        while(p.size() || s.size()){
            if(p.size() == 0 || s.size() == 0){
                ok = false;
                break;
            }
            if(p.back() != s.back()){
                ok = false;
                break;
            }
            char l = p.back();
            int cp = 0, cs = 0;
            while(p.size() && p.back() == l){
                cp++;
                p.pop_back();
            }
            while(s.size() && s.back() == l){
                cs++;
                s.pop_back();
            }
            if(cs < cp || 2*cp < cs){
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
