#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 305;
ll d[N][N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll curd = 0;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        cin >> d[i][j];
        curd += d[i][j];
    }
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        int a, b, c;
        cin >> a >> b >> c;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                int x = min(d[j][a] + c + d[b][k], d[j][b] + c + d[a][k]);
                if(d[j][k] > x){
                    curd -= (d[j][k] - x);
                    d[j][k] = x;
                }
            }
        }
        cout << curd/2 << " ";
    }
}
