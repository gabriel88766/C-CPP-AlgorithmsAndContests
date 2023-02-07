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
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        map<char,int> mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        bool ok = true;
        if(s.size() != 5) ok = false;
        if(mp['T'] != 1) ok = false;
        if(mp['i'] != 1) ok = false;
        if(mp['m'] != 1) ok = false;
        if(mp['u'] != 1) ok = false;
        if(mp['r'] != 1) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
