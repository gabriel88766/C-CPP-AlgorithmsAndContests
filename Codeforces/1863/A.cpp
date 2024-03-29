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
    int t;
    cin >> t;
    while(t--){
        int n, a, q;
        string s;
        cin >> n >> a >> q >> s;
        int cnt = a, cntp = 0;
        bool ok = false;
        if(cnt == n) ok = true;
        for(int i=0;i<q;i++){
            if(s[i] == '+') cnt++, cntp++;
            else cnt--;
            if(cnt == n) ok = true;
        }
        if(ok) cout << "YES\n";
        else if(cntp+a >= n) cout << "MAYBE\n";
        else cout << "NO\n";
    }
}
