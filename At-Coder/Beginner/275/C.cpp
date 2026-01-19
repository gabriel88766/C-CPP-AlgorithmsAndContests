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
    vector<string> vs(9);
    for(int i=0;i<9;i++) cin >> vs[i];
    int ans = 0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            for(int dx=-8;dx<9;dx++){
                for(int dy=-8;dy<9;dy++){
                    if(dx == 0 && dy == 0) continue;
                    int x1 = i, y1 = j;
                    int x2 = x1 + dx, y2 = y1 + dy;
                    int x31 = x2 - dy, y31 = y2 + dx;
                    int x41 = x31 - dx, y41 = y31 - dy;
                    int x32 = x2 + dy, y32 = y2 - dx;
                    int x42 = x32 - dx, y42 = y32 - dy;
                    auto check = [&](int x, int y){
                        if(x >= 0 && x < 9 && y >= 0 && y < 9 && vs[x][y] == '#') return true;
                        else return false;
                    };
                    if(check(x1, y1) && check(x2, y2) && check(x31, y31) && check(x41, y41)) ans++;
                    if(check(x1, y1) && check(x2, y2) && check(x32, y32) && check(x42, y42)) ans++;

                }
            }
        }
    }
    ans /= 8;
    cout << ans << "\n";
}

