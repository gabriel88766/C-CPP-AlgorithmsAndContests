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
        cin >> n >> m >> k;
        vector<vector<char>> gr(n, vector<char>(m));
        vector<vector<bool>> vis(n, vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> gr[i][j];
            }
        }
        bool ok = true;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(gr[i][j] == '*'){
                    //bfs.
                    if(!vis[i][j]){
                        int mv = 0;
                        vis[i][j] = true;
                        for(int x=1;;x++){
                            int di = i-x;
                            int dj1 = j-x;
                            int dj2 = j+x;
                            if(dj1 < 0) break;
                            if(dj2 > m) break;
                            if(di < 0) break;
                            if(gr[di][dj1] == '*' && gr[di][dj2] == '*'){
                                mv = x;
                                vis[di][dj1] = vis[di][dj2] = true;
                            }else break;
                        }
                        if(mv < k) ok = false;
                    }else{
                        int mv = 0;
                        for(int x=1;;x++){
                            int di = i-x;
                            int dj1 = j-x;
                            int dj2 = j+x;
                            if(dj1 < 0) break;
                            if(dj2 > m) break;
                            if(di < 0) break;
                            if(gr[di][dj1] == '*' && gr[di][dj2] == '*'){
                                mv = x;
                                //vis[di][dj1] = vis[di][dj2] = true;
                            }else break;
                        }
                        if(mv >= k){
                            for(int x=1;;x++){
                                int di = i-x;
                                int dj1 = j-x;
                                int dj2 = j+x;
                                if(dj1 < 0) break;
                                if(dj2 > m) break;
                                if(di < 0) break;
                                if(gr[di][dj1] == '*' && gr[di][dj2] == '*'){
                                    vis[di][dj1] = vis[di][dj2] = true;
                                }else break;
                            }
                        }
                    }
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
