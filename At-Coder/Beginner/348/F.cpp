#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int gr[2001][2001];
bitset<2001> bs[2001];
vector<int> vx[1000];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<=1000;i++) vx[i].reserve(2000);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> gr[i][j];
        }
    }
    bitset<2001> bcur;
    for(int j=1;j<=m;j++){
        for(int num=1;num<=999;num++) vx[num].clear();
        for(int i=1;i<=n;i++) vx[gr[i][j]].push_back(i);
        for(int num=1;num<=999;num++){
            bcur.reset();
            for(auto &x : vx[num]){
                bcur[x] = 1;
            }
            for(auto &x : vx[num]){
                bcur[x] = 0;
                bs[x] ^= bcur;
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) ans += bs[i].count();
    cout << ans << "\n";
}
