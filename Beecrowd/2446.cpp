#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
bitset<N> bs[2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    bs[0][0] = 1;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        bs[1] = bs[0];
        if(x <= n){
            bs[1] |= (bs[0] << x);
        }
        bs[0] = bs[1];
    }
    if(bs[1][n]) cout << "S\n";
    else cout << "N\n";
}
