#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
int c[N], r[N], d1, d2;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    int ans = -1;
    for(int i=1;i<=m;i++){
        int x;
        cin >> x;
        --x;
        int row = x/n;
        int col = x % n;
        c[col]++;
        r[row]++;
        if(row == col) d1++;
        if(row == (n - col - 1)) d2++;
        if(c[col] == n || r[row] == n || d1 == n || d2 == n){
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
}
