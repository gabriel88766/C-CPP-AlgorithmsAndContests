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
    int n = s.size();
    bool ok = true;
    string x = s;
    reverse(x.begin(), x.end());
    if(x != s) ok = false;
    string s1 = s.substr(0, (n-1)/2);
    string s2 = s.substr((n+1)/2, (n-1)/2);
    string x1 = s1, x2 = s2;
    reverse(x1.begin(), x1.end());
    reverse(x2.begin(), x2.end());
    if(x1 != s1) ok = false;
    if(x2 != s2) ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}   
