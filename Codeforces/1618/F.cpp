#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string to_bin(ll a){
    int msb = 63-__builtin_clzll(a);
    string ans;
    for(int j=msb;j>=0;j--){
        if(a & (1LL << j)) ans += '1';
        else ans += '0';
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll a, b;
    cin >> a >> b;
    string s = to_bin(a);
    vector<string> ap;
    ap.push_back(s + "1");
    ap.push_back(ap[0]);
    reverse(ap[1].begin(), ap[1].end());
    while(s.back() == '0') s.pop_back();
    ap.push_back(s);
    ap.push_back(s);
    reverse(ap[3].begin(), ap[3].end());
    string ls = to_bin(b);
    bool ok = false;
    if(a == b) ok = true;
    for(auto &s : ap){
        for(int i=0;i<ls.size();i++){
            if(i + s.size() <= ls.size()){
                if(ls.substr(0, i) == string(i, '1') && ls.substr(i+s.size(), ls.size() - i - s.size()) == string(ls.size()-i-s.size(), '1')){
                    if(ls.substr(i, s.size()) == s){
                        ok = true;
                    }
                }
            }
        }
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
