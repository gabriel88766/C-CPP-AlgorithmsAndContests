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
    int m, k;
    cin >> m >> k;
    int x = 0;
    if(m == 1 && k == 0){
        cout << "0 0 1 1\n";
        return 0;
    }
    for(int i=0;i<(1 << m);i++) if(i != k) x ^= i;
    if(x == k){
        cout << k << " ";
        for(int i=(1 << m)-1;i>=0;i--) if(i != k) cout << i << " ";
        cout << k << " ";
        for(int i=0;i<(1 << m);i++) if(i != k) cout << i << " ";
    }else cout << -1;
}
