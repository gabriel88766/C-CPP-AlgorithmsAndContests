#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<char>> matrix(n+2, vector<char>(m+2, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrix[i][j] == '.'){
                ans++;
                queue<pair<int,int>> q;
                q.push({i, j});
                matrix[i][j] = '#';
                while(!q.empty()){
                    auto p = q.front();
                    q.pop();
                    
                    if(matrix[p.first+1][p.second] == '.') {
                        q.push({p.first+1, p.second});
                        matrix[p.first+1][p.second] = '#';
                    }
                    if(matrix[p.first-1][p.second] == '.') {
                        q.push({p.first-1, p.second});
                        matrix[p.first-1][p.second] = '#';
                    }
                    if(matrix[p.first][p.second+1] == '.') {
                        q.push({p.first, p.second+1});
                        matrix[p.first][p.second+1] = '#';
                    }
                    if(matrix[p.first][p.second-1] == '.') {
                        q.push({p.first, p.second-1});
                        matrix[p.first][p.second-1] = '#';
                    }
                }
            }   
        }
    }
    cout << ans;
}
