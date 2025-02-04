#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int vs[N][30], vns[N][30];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, c;
    cin >> n >> c;
    //init
    for(int i=0;i<30;i++) vs[0][i] = 1;
    for(int i=1;i<=n;i++){
        int t, x;
        cin >> t >> x;
        int nc = 0;
        for(int j=0;j<30;j++){
            int b;
            if(x & (1 << j)) b = 1;
            else b = 0;
            if(t == 1){
                vs[i][j] = vs[i-1][j] & b;
                vns[i][j] = vns[i-1][j] & b;
            }else if(t == 2){
                vs[i][j] = vs[i-1][j] | b;
                vns[i][j] = vns[i-1][j] | b;
            }else{
                vs[i][j] = vs[i-1][j] ^ b;
                vns[i][j] = vns[i-1][j] ^ b;
            }
            if(c & (1 << j)){
                if(vs[i][j]) nc |= (1 << j);
            }else{
                if(vns[i][j]) nc |= (1 << j);
            }
        }
        c = nc;
        cout << c << "\n";
    }
}
