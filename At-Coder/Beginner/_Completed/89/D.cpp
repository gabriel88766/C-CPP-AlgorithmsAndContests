#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int d[303*303][18]; //binary lift 2^x jumps
pair<int,int> mp[303*303];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, D;
    cin >> h >> w >> D;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            int x;
            cin >> x;
            mp[x] = make_pair(i, j);
        }
    }
    for(int i=1;i<=h*w-D;i++){
        d[i][0] = abs(mp[i+D].first - mp[i].first) + abs(mp[i+D].second - mp[i].second);
    }
    for(int j=1;j<18;j++){
        ll jmp = (1 << j);
        jmp *= D;
        if(jmp >= h*w) break;
        for(int i=1;i<=h*w-jmp;i++){
            d[i][j] = d[i][j-1] + d[i + (jmp >> 1)][j-1];
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        ll a, b;
        cin >> a >> b;
        int ans = 0;
        for(int j=17;j>=0;j--){
            ll jmp = 1 << j;
            jmp *= D;
            if(a+jmp <= b){
                ans += d[a][j];
                a += jmp;
            }
        }
        cout << ans << "\n";
    }
}
