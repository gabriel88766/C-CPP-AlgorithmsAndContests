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
    int h, w;
    cin >> h >> w;
    vector<string> vs(h);
    for(int i=0;i<h;i++) cin >> vs[i];
    int ans = 0;
    for(int i=1;i<h;i++){
        bool ct = false;
        for(int j=0;j<w;j++){
            if(vs[i][j] != vs[i-1][j]){
                if(!ct){
                    ct = true;
                    ans++;
                }
            }else ct = false;
        }
    }
    for(int j=1;j<w;j++){
        bool ct = false;
        for(int i=0;i<h;i++){
            if(vs[i][j] != vs[i][j-1]){
                if(!ct){
                    ct = true;
                    ans++;
                }
            }else ct = false;
        }
    }
    cout << ans << "\n";
}
