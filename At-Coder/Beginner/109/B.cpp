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
    int n;
    cin >> n;
    map<string, bool> mp;
    string ls;
    bool ok = true;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(i != 0){
            if(ls.back() != s[0]) ok = false;
        }
        ls = s;
        if(mp.count(s)) ok = false;
        mp[s] = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
