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
    string s;
    cin >> s;
    if(!(s.size() % 2)){
        bool ok = true;
        set<char> sx;
        for(int i=0;i<s.size();i+=2){
            if(s[i] != s[i+1]) ok = false;
            if(sx.count(s[i])) ok = false;
            sx.insert(s[i]);
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }else cout << "No\n";
}
