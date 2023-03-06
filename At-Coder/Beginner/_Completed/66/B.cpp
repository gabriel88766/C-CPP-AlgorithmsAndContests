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
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size();
    int sz = 0;
    for(int i=2;i<n;i+=2){
        int szs = i/2;
        bool ok = true;
        for(int j=0;j<szs;j++) if(s[j] != s[j+szs]) ok = false;
        if(ok) sz = i;
    }
    cout << sz;
}
