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
        int n, m;
        cin >> n >> m;
        tuple<int, int, int> bg = {-INF_INT, -INF_INT, -INF_INT};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x;
                cin >> x;
                tuple<int, int, int> cur = {x, i, j};
                bg = max(bg, cur);
            }
        }
        int x = get<1>(bg);
        int y = get<2>(bg);
        cout <<  max(x, n-x+1) * max(y, m-y+1) << "\n";
    }
}
