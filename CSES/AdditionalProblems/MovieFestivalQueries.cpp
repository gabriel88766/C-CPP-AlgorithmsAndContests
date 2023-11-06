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
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> m(n);
    for(int i=0;i<n;i++){
        cin >> m[i].first >> m[i].second;
    }
    sort(m.begin(), m.end(), [&](pair<int,int> u, pair<int,int> v){
        if(u.second != v.second) return u.second < v.second;
        else return u.first > v.first;
    });
    vector<vector<int>> adj(1e6+2, vector<int>(20, 0)), adjw(1e6+2, vector<int>(20, 0));
    int c = 1, mv = 0;
    for(int i=0;i<m.size();i++){
        if(m[i].first < c) continue;
        for(int j=c;j<m[i].first;j++){
            adj[j][0] = m[i].first;
            adjw[j][0] = 0;
        }
        adj[m[i].first][0] = m[i].second;
        adjw[m[i].first][0] = 1;
        c = m[i].first+1;
        mv = max(mv, m[i].second);
    }
    adj[mv][0] = 1000001;
    adj[1000001][0] = 1000001;
    for(int i=1;i<20;i++){
        for(int j=1;j<=mv;j++){
            adj[j][i] = adj[adj[j][i-1]][i-1];
            adjw[j][i] = adjw[j][i-1] + adjw[adj[j][i-1]][i-1];
        }
        adj[1000001][i] = 1000001;
    }
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for(int j=19;j>=0;j--){
            if(adj[a][j] <= b){
                ans += adjw[a][j];
                a = adj[a][j];
            }
        }
        cout << ans << "\n";
    }
}
