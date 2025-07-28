#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cases[2][4] = {{2, 1, 0, 1}, {1, 2, 1, 0}};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    --c; d--;
    ll ans = 0;
    for(int i=0;i<4;i++){
        ll fl = a, fr = c;
        while(((fr%4) + 4) % 4 != i) fr--;
        while(((fl % 4) + 4) % 4 != i) fl++;
        if(fr >= fl){
            ll tt = (fr - fl)/4 + 1;
            for(int j=0;j<2;j++){
                ll fyl = b, fyr = d;
                while(((fyr%2) + 2) % 2 != j) fyr--;
                while(((fyl % 2) + 2) % 2 != j) fyl++;
                if(fyr >= fyl){
                    ll tt2 = (fyr - fyl)/2 + 1;
                    //8 cases;
                    ans += tt * tt2 * cases[j][i];
                }
            }
        }
    }
    cout << ans << "\n";
}
