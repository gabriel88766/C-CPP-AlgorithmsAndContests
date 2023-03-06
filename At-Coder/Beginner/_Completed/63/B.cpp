#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int mp[26];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    bool ok = true;
    cin >> s;
    for(int i=0;i<s.size();i++) mp[s[i]-'a']++;
    for(int i=0;i<26;i++) if(mp[i] > 1) ok = false;
    if(ok) cout << "yes";
    else cout << "no";
}
