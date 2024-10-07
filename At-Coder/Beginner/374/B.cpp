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
    if(s == t) cout << "0\n";
    else{
        for(int i=0;i<max(s.size(), t.size()); i++){
            if(i < t.size() && i < s.size() && s[i] == t[i]) continue;
            else{
                cout << i+1 << "\n";
                break;
            }
        }
    }
}
