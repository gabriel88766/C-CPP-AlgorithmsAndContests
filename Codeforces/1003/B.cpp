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
    //freopen(" in", "r", stdin); test input
    int a,b,x;
    string ans;
    cin >> a >> b >> x;
    char cur;
    if(b > a) cur = 1, b--; 
    else cur = 0, a--;
    ans += cur + '0';
    while(x > 1){
        cur ^= 1;
        ans += '0'+cur;
        if(cur == 1) b--;
        else a--;
        x--;
    }
    if(cur == 1){
        for(int i=0;i<b;i++) ans += "1";
        for(int i=0;i<a;i++) ans += "0";
    }else{
        for(int i=0;i<a;i++) ans += "0";
        for(int i=0;i<b;i++) ans += "1";
    }
    cout << ans;
}
