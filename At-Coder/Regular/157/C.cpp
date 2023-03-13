#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e4+2; //O(N) preprocessing, O(1) query

ll fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = (fat[i-1]*i) % MOD;
    }
    ll aux = MOD - 2, aux2 = fat[N-1];
    while(aux){
        if(aux & 1) invfat[N-1] = (invfat[N-1] * aux2) % MOD;
        aux2 = (aux2 * aux2) % MOD;
        aux >>= 1;
    }
    for(int i=N-2;i>=0;i--) invfat[i] = (invfat[i+1] * (i + 1)) % MOD;
}
ll nCr(ll a, ll b){
    return (((fat[a] * invfat[a-b]) % MOD) * invfat[b]) % MOD;
}

char grid[2005][2005];
ll SumSq[2005][2005], Sum[2005][2005];
ll cnt[2005][2005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int H, W;
    cin >> H >> W;
    for(int i=1;i<=H;i++) for(int j=1;j<=W;j++) cin >> grid[i][j];
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            ll auxSum=0, auxSumSq=0;
            if(j >= 1){
                auxSum = Sum[i][j-1];
                auxSumSq = SumSq[i][j-1];
                if(grid[i][j] == 'Y' && grid[i][j-1] == 'Y'){
                    auxSumSq = (auxSumSq + 2 * auxSum + nCr(i+j-3, j-2)) % MOD;
                    auxSum = (auxSum + nCr(i+j-3, j-2)) % MOD;
                    cnt[i][j] = nCr(i+j-3,j-2) % MOD;
                }else cnt[i][j] = cnt[i][j-1];
            }
            if(i >= 1){
                Sum[i][j] = Sum[i-1][j];
                SumSq[i][j] = SumSq[i-1][j];
                if(grid[i][j] == 'Y' && grid[i-1][j] == 'Y'){
                    SumSq[i][j] = (SumSq[i][j] + 2 * Sum[i][j] + nCr(i+j-3, i-2)) % MOD;
                    Sum[i][j] = (Sum[i][j] + nCr(i+j-3,i-2) ) % MOD;
                    cnt[i][j] = (cnt[i][j] + nCr(i+j-3,i-2)) % MOD;
                }else cnt[i][j] = (cnt[i][j] + cnt[i-1][j]) % MOD;
            }
            Sum[i][j] = (Sum[i][j] + auxSum) % MOD;
            SumSq[i][j] = (SumSq[i][j] + auxSumSq) % MOD;
        }
    }
    cout << SumSq[H][W];

}
