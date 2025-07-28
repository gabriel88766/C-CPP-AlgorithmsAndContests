#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
int ans[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> vx(2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int l = min(min(i, n-i+1), min(j, n-j+1));
            vx[l%2].push_back({i, j});
        }
    }
    int p2 = n*n;
    int p1 = 1;
    while(vx[0].size()){
        ans[vx[0].back().first][vx[0].back().second] = p1++;
        vx[0].pop_back();
    }
    while(vx[1].size()){
        ans[vx[1].back().first][vx[1].back().second]= p2--;
        vx[1].pop_back();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
