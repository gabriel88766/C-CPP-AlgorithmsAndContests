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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<bool>> gr(n+2, vector<bool>(m+2, true));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            gr[i][j] = false;
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //type 1
            int fr = n - i;
            int fc = m - j;
            if(fc <= fr) ans += 2*fc + 1;
            else ans += 2*(fr+1);
            //type 2
            if(fr <= fc) ans += 2*fr + 1;
            else ans += 2*(fc+1);
            //type 1 and 2.
            ans--;
        }
    }
    for(int i=0;i<q;i++){
        //brute force....
        int x, y;
        cin >> x >> y;
        //type 1 back and forth
        int cx = x, cy = y;
        ll cur = 0;
        ll l = 0, r = 0;
        for(int j=0;;j++){
            if(j % 2) cx--;
            else cy--;
            if(gr[cx][cy]){
                l = j+1;
                break;
            }
        }
        cx = x, cy = y;
        for(int j=0;;j++){
            if(j % 2) cy++;
            else cx++;
            if(gr[cx][cy]){
                r = j+1;
                break;
            }
        }
        cur += l*r;
        //2
        cx = x, cy = y;
        l = 0, r = 0;
        for(int j=0;;j++){
            if(j % 2) cy--;
            else cx--;
            if(gr[cx][cy]){
                l = j+1;
                break;
            }
        }
        cx = x, cy = y;
        for(int j=0;;j++){
            if(j % 2) cx++;
            else cy++;
            if(gr[cx][cy]){
                r = j+1;
                break;
            }
        }
        cur += l * r;
        cur--;
        if(gr[x][y]) ans += cur;
        else ans -= cur;
        if(gr[x][y]) gr[x][y] = false;
        else gr[x][y] = true;
        cout << ans << "\n";

    }
}
