#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

set<char> mr = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

char mirror(char a){
    if(mr.count(a)) return a;
    else return '.';
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());
    bool ok = true;
    for(int i=0;i<s.size();i++){
        if(mirror(s[i]) != rev[i]) ok = false;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
