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
    int n = s.size();
    bool ok = false;
    assert(n <= 100);
    for(int i=0;i<=n-1;i++){
        bool cok = true;
        for(int j=0;j<n;j++){
            int p = (i+j) % n;
            if(s[p] != t[j]) cok = false;
        }
        if(cok) ok = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
