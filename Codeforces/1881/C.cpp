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
        int n;
        cin >> n;
        vector<vector<char>> v(n, vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> v[i][j];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // i, j => j, n-i-1
                pair<int,int> p1 = {i, j};
                pair<int,int> p2 = {p1.second, n-p1.first-1};
                pair<int,int> p3 = {p2.second, n-p2.first-1};
                pair<int,int> p4 = {p3.second, n-p3.first-1};
                char let[] = {v[p1.first][p1.second], v[p2.first][p2.second], v[p3.first][p3.second], v[p4.first][p4.second]};
                char maxl = 'a';
                for(int i=0;i<4;i++) maxl = max(maxl, let[i]);
                for(int i=0;i<4;i++) ans += maxl-let[i];
            }
        }
        cout << ans/4 << "\n";

    }
}
