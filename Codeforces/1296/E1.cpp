#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 205;
int adj[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(s[i] > s[j]){
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }
    bool ok = true;
    vector<int> ans(n+1, -1);
    for(int i=1;i<=n;i++){
        if(ans[i] == -1){
            queue<int> q;
            q.push(i);
            ans[i] = 0;
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(int j=1;j<=n;j++){
                    if(adj[u][j]){
                        if(ans[j] == -1){
                            ans[j] = ans[u] ^ 1;
                            q.push(j);
                        }else if(ans[j] != (ans[u] ^ 1)){
                            ok = false;
                        }
                    }
                }
            }
            
        }
    }
    if(ok){
        cout << "YES\n";
        for(int i=1;i<=n;i++) cout << ans[i];
        cout << "\n";
    }else{
        cout << "NO\n";
    }
}
