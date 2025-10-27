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
        int n, m, k;
        string s;
        cin >> n >> m >> k >> s;
        s = " " + s;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        vector<vector<int>> win(2*k+1, vector<int>(n+1, 0)); // 1 is bob, 0 is alice
        for(int i=1;i<=n;i++){
            win[0][i] = s[i] == 'A' ? 0 : 1;
        }
        for(int i=1;i<=2*k;i++){
            for(int j=1;j<=n;j++){
                //if i % 2 == 1, then it's bob. he will aim some place with win = 1
                //if i % 2 == 0, then it's alice, she will aim some place with win = 0
                int c0 = 0, c1 = 0;
                for(auto v : adj[j]){
                    if(win[i-1][v] == 0) c0++;
                    else c1++;
                }
                if(i % 2){
                    if(c1) win[i][j] = 1;
                    else win[i][j] = 0;
                }else{
                    if(c0) win[i][j] = 0;
                    else win[i][j] = 1;
                }
            }
        }
        if(win[2*k][1]) cout << "Bob\n";
        else cout << "Alice\n";
    }
}
