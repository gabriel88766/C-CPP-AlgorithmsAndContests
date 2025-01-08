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
        ll n, d;
        cin >> n >> d;
        vector<bool> ok(10, false);
        ok[1] = true;
        if(d == 5) ok[5] = true;
        if(d == 7 || n >= 3) ok[7] = true;

        if(d == 9) ok[9] = ok[3] = true;
        else if(d == 3 || d == 6){
            if(n >= 3) ok[9] = ok[3] = true;
            else ok[3] = true;
        }else{
            if(n >= 6) ok[9] = ok[3] = true;
            else if(n >= 3) ok[3] = true;
        }


        for(int i=1;i<=9;i++) if(ok[i]) cout << i << " ";
        cout << "\n";
    }
}
