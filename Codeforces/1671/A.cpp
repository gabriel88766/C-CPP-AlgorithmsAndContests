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
        string s;
        cin >> s;
        char lc = 'z';
        int cnt = 0;
        bool ok = true;
        for(auto c : s){
            if(c != lc){
                if(cnt == 1) ok = false;
                cnt = 1;
                lc = c;
            }else cnt++;
        }
        if(cnt == 1) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

