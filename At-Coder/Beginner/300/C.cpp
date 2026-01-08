#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int h,w;

char gr[105][105];
int ans[105];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >>gr[i][j];
        }
    }
    int mn = min(h, w);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(gr[i][j] == '#'){
                int d = 0;
                for(int k=1;;k++){
                    if(gr[i+k][j+k] == '#' && gr[i+k][j-k] == '#' && gr[i-k][j+k] == '#' && gr[i-k][j-k] == '#') d++;
                    else break;
                }
                ans[d]++;
            }
        }
    }
    for(int j=1;j<=mn;j++){
        cout << ans[j] << " ";
    }
    cout << "\n";
}
