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
        int n, m, k;
        cin >> n >> m >> k;
        int qt2 = min(n-1, m); //1, 2, 3, ..., n-1 
        if(m >= n){ //n, 2n, ...
            qt2 += m/n;
        }
        if(k > 3) cout << "0\n";
        else if(k == 3){
            cout << m - qt2 << "\n";
        }else if(k == 2){
            cout << qt2 << "\n";
        }else{//k == 1
            cout << "1\n";
        }
    }
}
