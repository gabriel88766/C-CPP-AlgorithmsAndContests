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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> s(n, vector<char>(n)), t(m, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> s[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin >> t[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i + m - 1 < n && j + m - 1 < n){
                bool ok = true;
                for(int u=0;u<m;u++){
                    for(int v=0;v<m;v++){
                        if(t[u][v] != s[i+u][j+v]) ok = false;
                    }
                }
                if(ok) cout << i+1 << " " << j+1 << "\n";
            }
        }
    }
}
