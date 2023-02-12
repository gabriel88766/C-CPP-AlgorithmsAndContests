#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.);
using namespace std;

const int N = 2e5+3;
ll ans[N];
ll pot[N];
void init(){
    pot[0] = 1;
    for(int i=1;i<N;i++) pot[i] = (pot[i-1] * 2) % MOD;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    init();
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        ans[1] = 1;
        int cnt = 0;
        char cur = s[0];
        for(int i=2;i<=n;i++){
            if(s[i-1] == cur) cnt++;
            else{
                cnt = 0;
                cur = s[i-1];
            }
            ans[i] = (pot[cnt] + ans[i-1]) % MOD; 
        }
        cout << ans[n] << "\n";
        for(int i=1;i<=n;i++) ans[i] = 0;
    }
}
