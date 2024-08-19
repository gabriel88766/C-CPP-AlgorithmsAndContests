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
        int cx = 0, cy = 0, mnx = 0, mny = 0, mxx = 0, mxy = 0;
        string s;
        cin >> s;
        for(int i=0;i<s.size();i++){
            int sx = 0, sy = 0;
            if(s[i] == 'L') sx = -1;
            if(s[i] == 'R') sx = 1;
            if(s[i] == 'U') sy = -1;
            if(s[i] == 'D') sy = 1;
            cx += sx;
            cy += sy;
            if(cx - mnx == m) break;
            if(mxx - cx == m) break;
            if(cy - mny == n) break;
            if(mxy - cy == n) break;
            mnx = min(mnx, cx);
            mxx = max(mxx, cx);
            mny = min(mny, cy);
            mxy = max(mxy, cy);
        }
        int x = 1 + abs(mnx);
        int y = 1 + abs(mny);
        cout << y << " " << x << "\n";
    }
}
