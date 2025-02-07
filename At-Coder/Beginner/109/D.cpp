#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int gr[505][505];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int, int>> ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin >> x;
            gr[i][j] += x;
            if(gr[i][j] % 2){
                if(j == m){
                    if(i != n){
                        ans.push_back({i, j, i+1, j});
                        gr[i+1][j]++;
                    }
                }else{
                    ans.push_back({i, j, i, j+1});
                    gr[i][j+1]++;
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto [a, b, c, d] : ans) cout << a << " " << b << " " << c << " " << d << "\n";
}
