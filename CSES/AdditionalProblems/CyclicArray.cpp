#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20;
ll jmp[N][M];
int n;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll k;
    cin >> n >> k;
    vector<ll> v(n), ps(2*n+1);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum += v[i];
    }
    if(sum <= k){
        cout << "1\n";
        return 0;
    }
    ps[0] = v[0];
    for(int i=1;i<2*n;i++){
        ps[i] = ps[i-1] + v[i%n];
    }
    for(int i=1;i<=n;i++){
        int x = i;
        for(int j=n/2;j>=1;j>>=1){
            while(x+j < 2*n && ps[x+j] - ps[i-1] <= k) x += j;
        }
        jmp[i%n][0] = x - i + 1;
    }
    for(int i=1;i<M;i++){
        for(int j=0;j<n;j++){
            jmp[j][i] = min((ll)n, jmp[j][i-1] + jmp[(j+jmp[j][i-1])%n][i-1]);
        }
    }
    int ans = INF_INT;
    for(int i=0;i<n;i++){
        int cur = 0;
        int jp = 0;
        int curi = i;
        for(int j=M-1;j>=0;j--){
            while(jmp[curi][j] + jp < n){
                jp += jmp[curi][j];
                curi = (i + jp)%n;
                cur += (1 << j);
            }
        }
        cur++;
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}
