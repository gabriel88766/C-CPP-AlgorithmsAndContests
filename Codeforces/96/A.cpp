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
    bool ok = true;
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0;i<n-6;i++){
        bool cur = true;
        for(int j=i+1;j<=i+6;j++){
            if(s[j] != s[i]) cur = false;
        }
        if(cur) ok = false;
    }
    if(ok) cout << "NO\n";
    else cout << "YES\n";
}
