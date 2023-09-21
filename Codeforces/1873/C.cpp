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
        vector<vector<char>> v(10, vector<char>(10));
        int ans = 0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cin >> v[i][j];
                int pos = min(min(i+1, 10-i), min(j+1, 10-j));
                if(v[i][j] == 'X') ans += pos;
            }
        }
        cout << ans << "\n";
    }
}
