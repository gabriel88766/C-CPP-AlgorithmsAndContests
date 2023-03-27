#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,1,-1};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //f reopen("in", "r", stdin); //test input
    vector<pair<int,int>> b;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> ch(n, vector<char>(m));
    vector<vector<char>> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ch[i][j];
            if(ch[i][j] > '0' && ch[i][j] <= '9') b.push_back({i, j});
        }
    }
    ans = ch;
    for(auto x : b){
        int val = ch[x.first][x.second]-'0';
        for(int i=0;i<=val;i++){
            for(int j=0;i+j<=val;j++){
                for(int k=0;k<4;k++){
                    int xd = x.first + i*dx[k];
                    int yd = x.second + j*dy[k];
                    if(xd < n && xd >= 0 && yd < m && yd >= 0){
                        ans[xd][yd] = '.';
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
