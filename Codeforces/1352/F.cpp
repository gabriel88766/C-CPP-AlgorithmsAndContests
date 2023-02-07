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
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        string sa,sb,sc, ans;
        for(int i=0;i<a;i++) sa += "0";
        if(a) sa += "0";
        for(int i=0;i<c;i++) sc += "1";
        if(c) sc += "1";
        ans = sa + sc;
        if(!a || !c) b++; //..
        if(!a && !c){
            ans = "1";
        }
        for(int i=0;i<(b-1);i++){
            if(ans[ans.size()-1] == '0') ans += "1";
            else ans += "0";
        }
        cout << ans << "\n";
    }
}
