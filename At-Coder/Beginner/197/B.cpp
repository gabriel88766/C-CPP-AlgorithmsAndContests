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
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<string> v(h);
    for(int i=0;i<h;i++) cin >> v[i];
    --x; y--;
    int ans = 1;
    for(int i=x-1;i>=0;i--){
        if(v[i][y] == '.') ans++;
        else break;
    }
    for(int i=x+1;i<h;i++){
        if(v[i][y] == '.') ans++;
        else break;
    }
    for(int j=y+1;j<w;j++){
        if(v[x][j] == '.') ans++;
        else break;
    }
    for(int j=y-1;j>=0;j--){
        if(v[x][j] == '.') ans++;
        else break;
    }
    cout << ans << "\n";
}
