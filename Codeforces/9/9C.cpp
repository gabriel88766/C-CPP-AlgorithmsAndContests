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
    //freopen("in", "r", stdin); test input
    int n, ans = 0, curpot=1;
    bool all1 = false;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(all1) s[i] = '1';
        if(s[i] - '0' >= 2){
            s[i] = '1';
            all1 = true;
        }
    }
    for(int i=(s.size()-1);i>=0;i--){
        if(s[i] == '1') ans += curpot;
        curpot <<=1;
    }
    cout << ans;
}
