#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool check(string a){
    for(int i=1;i<a.size();i++){
        if(a[i] == a[i-1]) return false;
    }
    return true;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        bool ok = (check(s) && check(t));
        string ss = s, st = t;
        for(int i=(n-1);i>=1;i--){
            st = st + ss[i];
            ss = ss.substr(0,i);
            if(check(ss) && check(st)) ok = true;
        }
        ss = s, st = t;
        for(int i=(m-1);i>=1;i--){
            ss = ss + st[i];
            st = st.substr(0,i);
            if(check(ss) && check(st)) ok = true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
 