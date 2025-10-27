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
    freopen("snake_scales_chapter_1_input.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout); //test input
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        int mx = 0;
        int x;
        cin >> x;
        for(int j=2;j<=n;j++){
            int nx;
            cin >> nx;
            mx = max(mx, abs(nx - x));
            x = nx;
        }
        cout << "Case #" << i << ": " << mx << "\n";
    }
}
