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
    int n, x;
    cin >> n >> x;
    int tt = 0;
    bool flag = false;
    for(int i=1;i<=n;i++){
        int v, p;
        cin >> v >> p;
        tt += v*p;
        if(tt > x*100){
            if(!flag){
                flag = true;
                cout << i << "\n";
            }
        }
    }
    if(!flag) cout << "-1\n";
}
