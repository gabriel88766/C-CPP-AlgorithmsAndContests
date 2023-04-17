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
    int a, b;
    string s;
    cin >> a >> b >> s;
    if(s.size() != (a+b+1)) cout << "No\n";
    else{
        bool ok = true;
        for(int i=0;i<a;i++) if(s[i] < '0' || s[i] > '9') ok = false;
        if(s[a] != '-') ok = false;
        for(int i=a+1;i<=a+b;i++) if(s[i] < '0' || s[i] > '9') ok = false;
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
