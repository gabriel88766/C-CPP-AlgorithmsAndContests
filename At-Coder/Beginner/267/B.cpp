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
    s = " " + s;
    if(s[1] == '0'){
        //cond 1
        int mn = -1;
        int mx = -1;
        if(s[7] == '1'){
            if(mn == -1) mn = 1;
            mx = 1;
        }
        if(s[4] == '1'){
            if(mn == -1) mn = 2;
            mx = 2;
        }
        if(s[2] == '1' || s[8] == '1'){
            if(mn == -1) mn = 3;
            mx = 3;
        }
        if(s[5] == '1'){
            if(mn == -1) mn = 4;
            mx = 4;
        }
        if(s[3] == '1' || s[9] == '1'){
            if(mn == -1) mn = 5;
            mx = 5;
        }
        if(s[6] == '1'){
            if(mn == -1) mn = 6;
            mx = 6;
        }
        if(s[10] == '1'){
            if(mn == -1) mn = 7;
            mx = 7;
        }
        bool ok = false;
        if(mn != mx){ 
            if(s[4] == '0'){
                if(mn < 2 && 2 < mx) ok = true;
            }
            if(s[2] == '0' && s[8] == '0'){
                if(mn < 3 && 3 < mx) ok = true;
            }
            if(s[5] == '0'){
                if(mn < 4 && 4 < mx) ok = true;
            }
            if(s[3] == '0' && s[9] == '0'){
                if(mn < 5 && 5 < mx) ok = true;
            }
            if(s[6] == '0'){
                if(mn < 6 && 6 < mx) ok = true;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }else cout << "No\n";
}
