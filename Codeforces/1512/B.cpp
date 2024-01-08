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
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j] == '*') vp.push_back({i, j});
            }
        }
        auto p1 = vp[0];
        auto p2 = vp[1];
        if(p1.first != p2.first && p1.second != p2.second){
            v[p1.first][p2.second] = '*';
            v[p2.first][p1.second] = '*';
        }else{
            if(p1.first == p2.first){
                int x = p1.first ? 0 : 1;
                v[x][p1.second] = v[x][p2.second] = '*';
            }else{
                int x = p1.second ? 0 : 1;
                v[p1.first][x] = v[p2.first][x] = '*';
            }
        }
        for(int i=0;i<n;i++) cout << v[i] << "\n";
    }
}
