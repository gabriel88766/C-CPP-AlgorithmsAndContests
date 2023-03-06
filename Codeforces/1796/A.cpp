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
    string  s = "FBFFBFFBFBFFBFFBFBFFBFFB";
    int t;
    cin >> t;
    while(t--){
        bool ok = false;
        string test;
        int n;
        cin >> n >> test;
        for(int i=0;i<8;i++){
            if(test == s.substr(i, n)) ok = true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
