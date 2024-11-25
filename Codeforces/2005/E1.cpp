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
        int l, n, m;
        cin >> l >> n >> m;
        vector<int> a(l);
        for(int i=0;i<l;i++) cin >> a[i];
        reverse(a.begin(), a.end());
        vector<vector<int>> v(n+1, vector<int>(m+1));
        vector<vector<int>> win(n+1, vector<int>(m+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> v[i][j];
            }
        }
        for(auto x : a){
            vector<vector<int>> nm(n+1, vector<int>(m+1, 0));
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    nm[i][j] = nm[i-1][j] + nm[i][j-1] - nm[i-1][j-1];
                    if(v[i][j] == x){
                        int qt = win[n][m] - win[i][m] - win[n][j] + win[i][j];
                        if(!qt) nm[i][j]++;
                    }
                }
            }
            win = nm;
        }
        if(win[n][m]) cout << "T\n";
        else cout << "N\n";

    }
}
