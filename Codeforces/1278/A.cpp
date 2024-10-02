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
        string a, b;
        cin >> a >> b;
        sort(a.begin(), a.end());
        bool ok = false;
        int sz = b.size();
        sz -= a.size();
        for(int i=0;i<=sz;i++){
            string cur = b.substr(i, a.size());
            sort(cur.begin(), cur.end());
            if(a == cur) ok = true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
