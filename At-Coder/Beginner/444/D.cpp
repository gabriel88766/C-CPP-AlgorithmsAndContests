#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[200015];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int mx = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cnt[x]++;
        mx = max(mx, x);
    }
    for(int i=mx-1;i>=1;i--) cnt[i] += cnt[i+1];
    string ans;
    int cur = 0;
    for(int i=1;i<=mx;i++){
        cur += cnt[i];
        int d = cur % 10;
        ans += d + '0';
        cur /= 10;
    }
    while(cur){
        ans += (cur % 10) + '0';
        cur /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}
