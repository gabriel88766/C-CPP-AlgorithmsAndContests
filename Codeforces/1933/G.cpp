#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


vector<vector<string>> types = {{"1100", "0011", "1100", "0011"}, {"0011", "1100", "0011", "1100"}, {"1010", "1010", "0101", "0101"},\
    {"0101", "0101", "1010", "1010"}, {"0110", "1001", "0110", "1001"}, {"0101", "1010", "1010", "0101"},\
    {"1001", "0110", "1001", "0110"}, {"1010", "0101", "0101", "1010"}, };


int get(int type, int i, int j){
    --i, --j;
    i %= 4, j %= 4;
    return types[type][i][j] - '0';
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        vector<int> ok(8, true);
        cout << 8 << "\n";
        int n, m, q;
        cin >> n >> m >> q;
        for(int i=0;i<q;i++){
            int x, y;
            cin >> x >> y;
            string s;
            cin >> s;
            int cur = s == "circle" ? 1 : 0;
            for(int j=0;j<8;j++){
                if(get(j, x, y) != cur) ok[j] = false;
            }
            int ans = 0;
            for(int j=0;j<8;j++) if(ok[j]) ans++;
            cout << ans << "\n";
        }
    }
}   
