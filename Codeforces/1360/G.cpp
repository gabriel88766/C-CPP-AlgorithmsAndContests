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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        priority_queue<pair<int, int>> pq;
        for(int i=1;i<=m;i++) pq.push({b, i});
        vector<vector<char>> ans(n+1, vector<char>(m+1, '0'));
        if(a * n == b * m){
            cout << "YES\n";
            for(int i=1;i<=n;i++){
                vector<pair<int, int>> ins;
                for(int j=0;j<a;j++){
                    auto [x, y] = pq.top();
                    pq.pop();
                    ans[i][y] = '1';
                    ins.push_back({x-1, y});
                }
                for(auto x : ins) pq.push(x);
                for(int j=1;j<=m;j++) cout << ans[i][j];
                cout << "\n";
            }
        }else cout << "NO\n";
    }
}
