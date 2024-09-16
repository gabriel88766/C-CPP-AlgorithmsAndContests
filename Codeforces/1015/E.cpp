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
    vector<string> gr(n);
    for(int i=0;i<n;i++) cin >> gr[i];
    vector<vector<int>> gst(n,vector<int>(m, INF_INT));

    for(int i=0;i<n;i++){
        int cur = 0;
        for(int j=0;j<m;j++){
            if(gr[i][j] == '*') gst[i][j] = min(gst[i][j], cur++);
            else gst[i][j] = cur = 0;
        }
        cur = 0;
        for(int j=m-1;j>=0;j--){
            if(gr[i][j] == '*') gst[i][j] = min(gst[i][j], cur++);
            else gst[i][j] = cur = 0;
        }
    }
    for(int j=0;j<m;j++){
        int cur = 0;
        for(int i=0;i<n;i++){
            if(gr[i][j] == '*') gst[i][j] = min(gst[i][j], cur++);
            else gst[i][j] = cur = 0;
        }
        cur = 0;
        for(int i=n-1;i>=0;i--){
            if(gr[i][j] == '*') gst[i][j] = min(gst[i][j], cur++);
            else gst[i][j] = cur = 0;
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i=0;i<n;i++){
        int gv = -1;
        for(int j=0;j<m;j++){
            if(gst[i][j]){
                for(int k=max(gv+1, j); k<=j+gst[i][j];k++){
                    vis[i][k] = true;
                }
                gv = max(gv, j+gst[i][j]);
            }
        }
        gv = m;
        for(int j=m-1;j>=0;j--){
            if(gst[i][j]){
                for(int k=min(gv-1, j); k>=j-gst[i][j];k--){
                    vis[i][k] = true;
                }
                gv = min(gv, j-gst[i][j]);
            }
        }
    }

    for(int j=0;j<m;j++){
        int gv = -1;
        for(int i=0;i<n;i++){
            if(gst[i][j]){
                for(int k=max(gv+1, i); k<=i+gst[i][j];k++){
                    vis[k][j] = true;
                }
                gv = max(gv, i+gst[i][j]);
            }
        }
        gv = n;
        for(int i=n-1;i>=0;i--){
            if(gst[i][j]){
                for(int k=min(gv-1, i); k>=i-gst[i][j];k--){
                    
                    vis[k][j] = true;
                }
                gv = min(gv, i-gst[i][j]);
            }
        }
    }
    bool ok = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(gr[i][j] == '*' && (!vis[i][j])) ok = false;
        }
    }
    if(ok){
        vector<tuple<int,int,int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(gst[i][j]) ans.push_back({i+1, j+1, gst[i][j]});
            }
        }
        cout << ans.size() << "\n";
        for(auto [a, b, c] : ans){
            cout << a << " " << b << " " << c << "\n";
        }
    }else cout << "-1\n";
}
 