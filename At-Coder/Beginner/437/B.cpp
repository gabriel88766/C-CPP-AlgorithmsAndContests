#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int gr[6][6];
bool cal[100];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, n;
    cin >> h >> w >> n;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cal[x] = true;
    }
    int mx = 0;
    for(int i=1;i<=h;i++){
        int cnt = 0;
        for(int j=1;j<=w;j++){
            if(cal[gr[i][j]]) cnt++;
        }
        mx = max(mx, cnt);
    }
    cout << mx << "\n";
}
