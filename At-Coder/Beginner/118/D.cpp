#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int len[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool al[10];
bitset<10001> dp[5002];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        assert(a < 10);
        al[a] = true;
    }
    assert(sizeof(len) == 10*sizeof(int));
    dp[0][0] = 1;
    int cnt = 0;
    int mx = 0;
    while(2*cnt <= n){
        for(int j=1;j<=9;j++){
            if(al[j]) dp[cnt+1] |= dp[cnt] << len[j];
        }
        ++cnt;
        assert(cnt <= 5001);
        if(dp[cnt][n]) mx = cnt;
    }
    int sz = n;
    string ans;
    assert(mx <= 5001);
    for(int i=mx;i>=1;i--){
        for(int j=9;j>=1;j--){
            if(al[j] && sz >= len[j] && dp[i-1][sz - len[j]]){
                ans += '0' + j;
                sz -= len[j];
                break;
            }
        }
    }
    cout << ans << "\n";
}
