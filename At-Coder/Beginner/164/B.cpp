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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int s = 0;
    while(a && c){
        if(s == 0){
            c = max(0, c - b);
        }else{
            a = max(0, a-d);
        }
        s ^= 1;
    }
    if(a == 0) cout << "No\n";
    else cout << "Yes\n";
}
