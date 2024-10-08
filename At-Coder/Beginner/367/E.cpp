#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int jp[200005][60];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k;
    vector<int> x(n+1), v(n+1);
    for(int i=1;i<=n;i++) cin >> x[i];
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++) jp[i][0] = x[i];
    for(int j=1;j<=59;j++){
        for(int i=1;i<=n;i++){
            jp[i][j] = jp[jp[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        int ans = i;
        for(int b=0;b<=59;b++){
            if(k & (1LL << b)) ans = jp[ans][b];
        }   
        cout << v[ans] << " ";
    }
    cout << "\n";
}
 