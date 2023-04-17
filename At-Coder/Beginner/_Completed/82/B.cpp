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
    string s,t;
    cin >> s >> t;
    char mins='z', maxt='a';
    for(auto x : s) mins = min(mins, x);
    for(auto x : t) maxt = max(maxt, x);
    if(mins != maxt){
        if(mins < maxt) cout << "Yes\n";
        else cout << "No\n";
    }else{
        int cs = 0, ct = 0;
        for(auto x : s) if(x == mins) cs++;
        for(auto x : t) if(x == maxt) ct++;
        if(cs == s.size()){
            if(cs < ct) cout << "Yes\n";
            else if(cs == ct && ct != t.size()) cout << "Yes\n";
            else cout << "No\n";
        }else cout << "No\n";
    }
}
