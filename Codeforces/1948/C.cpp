#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
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
        string s[2];
        cin >> s[0] >> s[1];
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(2, vector<bool>(n, false));
        q.push({0, 0});
        vis[0][0] = true;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int di = x + dx[k];
                int dj = y + dy[k];
                if(di == -1 || di == 2 || dj == -1 || dj == n) continue;
                if(s[di][dj] == '<') dj--;
                else dj++;
                if(!vis[di][dj]){
                    vis[di][dj] = true;
                    q.push({di, dj});
                }
            }   
        }
        if(vis[1][n-1]) cout << "YES\n";
        else cout << "NO\n";
    }
}
