#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char gr[12][12];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, d;
    cin >> h >> w >> d;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    int ans = 0;
    for(int x1=1;x1<=h;x1++){
        for(int y1=1;y1<=w;y1++){
            for(int x2=1;x2<=h;x2++){
                for(int y2=1;y2<=w;y2++){
                    if(x1 != x2 || y1 != y2){
                        if(gr[x1][y1] == '.' && gr[x2][y2] == '.'){
                            int cur = 0;
                            for(int i=1;i<=h;i++){
                                for(int j=1;j<=w;j++){
                                    if(gr[i][j] == '.'){
                                        if(abs(i-x1) + abs(j - y1) <= d) cur++;
                                        else if(abs(i-x2) + abs(j - y2) <= d) cur++;
                                    }
                                }
                            }
                            ans = max(ans, cur);
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
