#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+2;
int nxt[N][26];
int lws[26];
int dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k, q;
    string s;
    cin >> n >> k >> s >> q;
    for(int i=0;i<k;i++){
        lws[i] = n;
        nxt[n][i] = n;
    }
    //dp[n] = 0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<k;j++) nxt[i][j] = lws[j];
        lws[s[i]-'a'] = i;
        int mx = 0;
        for(int j=0;j<k;j++) mx = max(mx, nxt[i][j]);
        dp[i] =  dp[mx] + 1;
    }
    
    


    for(int i=0;i<q;i++){
        string cs;
        cin >> cs;
        int cn = lws[cs[0]-'a'];
        for(int j=1;j<cs.size();j++){
            cn = nxt[cn][cs[j]-'a'];
        }
        cout << dp[cn] << "\n";
    }
}
