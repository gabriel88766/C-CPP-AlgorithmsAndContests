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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m, -1));
        vector<vector<bool>> used(n, vector<bool>(m, false));
        if(m == 1){
            cout << "0\n";
            for(int i=0;i<n;i++) cout << "0\n";
        }else{
            //MEX 0 1 2, ..., min(n, m-1) (if n <= m)
            int mex = min(n+1, m);
            for(int i=1;i<=min(n, m-1); i++){
                for(int j=0;j<i; j++){
                    v[(j+i)%n][i] = j;
                    used[(j+i)%n][j] = true;
                }
            }
            for(int i=0; i < n; i++){
                int p = 0;
                stack<int> wrong, right;
                for(int j=0; j <= min(n, m-1); j++){
                    if(v[i][j] != -1) continue;
                    while(used[i][p]) ++p;
                    v[i][j] = p; 
                    used[i][p] = true; 
                    if(p == j) wrong.push(j);
                    else right.push(j);
                }
                while(!wrong.empty()){
                    if(wrong.size() >= 2){
                        int u = wrong.top();
                        wrong.pop();
                        int x = wrong.top();
                        wrong.pop();
                        right.push(u);
                        right.push(x);
                        swap(v[i][u], v[i][x]);
                    }else{
                        int u = wrong.top();
                        wrong.pop();
                        int x = right.top();
                        right.pop();
                        swap(v[i][u], v[i][x]);
                    }
                }
                for(int j=min(n, m-1)+1; j < m; j++){
                    while(used[i][p]) ++p;
                    v[i][j] = p; 
                    used[i][p] = true; 
                }
            }
            cout << mex << "\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout << v[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
}
