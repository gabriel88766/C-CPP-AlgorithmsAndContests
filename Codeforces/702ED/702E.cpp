#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//trying O(N log M) sparse table
const int N = 1e5+3, M = 35;
ll sum[N][M];
ll minw[N][M];
ll v[N][M];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, k;
    cin >> n >> k;
    ll pot[64];
    pot[0] = 1;
    for(int i=1;i<63;i++) pot[i] = 2 * pot[i-1];
    for(int i=0;i<n;i++) cin >> v[i][0];
    for(int i=0;i<n;i++) {
        cin >> sum[i][0];
        minw[i][0] = sum[i][0];
    }

    for(ll i=1; pot[i] <= k; i++){
        for(int j=0;j<n;j++){
            ll pos = v[j][i-1];
            sum[j][i] = sum[j][i-1] + sum[pos][i-1];
            minw[j][i] = min(minw[j][i-1], minw[pos][i-1]);
            v[j][i] = v[pos][i-1]; 
        }
    }

    for(int i=0;i<n;i++){
        ll sumc=0, mincur=INF_LL, curnode = i;
        for(ll j=0; pot[j] <= k; j++){
            if(pot[j] & k){
                sumc += sum[curnode][j];
                mincur = min(mincur, minw[curnode][j]);
                curnode = v[curnode][j];
            }
        }
        cout << sumc << " " << mincur << "\n";
    }
}
