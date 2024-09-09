#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 500005;
const int M = 750;
int sum[M+1][M+1];
int v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            v[x] += y;
            for(int i=1;i<=M;i++){
                sum[i][x%i] += y;
            }
        }else{
            if(x <= M) cout << sum[x][y] << "\n";
            else{
                int ans = 0;
                for(int j=y;j<N;j+=x){
                    ans += v[j];
                }
                cout << ans << "\n";
            }
        }
    }
}
