#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


int bn = 0;
void solve(vector<vector<int>> &ans, pair<int,int> cb, int sz){
    auto [x, y] = cb;
    for(int j=y; j<= y+sz-1; j++) ans[x][j] = ++bn;
    for(int j=x+1;j<=x+sz-1; j++) ans[j][y+sz-1] = ++bn;
    for(int j=y+sz-2;j>=y;j--) ans[x+sz-1][j] = ++bn;
    for(int j=x+sz-2;j>=x+1;j--) ans[j][y] = ++bn;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i=0;i<n/2;i++){
        solve(ans, {i, i}, n-2*i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == n/2 && j == n/2) cout << "T ";
            else cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
