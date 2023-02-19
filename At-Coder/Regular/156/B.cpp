#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 600005;
int mp[N];

ll fat[N], invfat[N];
void init(){
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
ll nCr(ll a, ll b){//MOD shall be prime!
    return (((fat[a] * invfat[a-b]) % MOD) * invfat[b]) % MOD;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    //naive
    int n, k;
    cin >> n >> k;
    init();
    vector<int> mexcur;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        mp[aux]++;
    }
    int mexmax = 0, cnt = 0;
    mexcur.emplace_back(0);//1indexed
    while(true){
        if(mp[mexmax]) mexmax++;
        else{
            mexcur.emplace_back(mexmax);
            cnt++;
            if(cnt == k) break;
            mexmax++;
        }
    }
    mexcur.emplace_back(mexmax+1);
    ll ans = 0;
    for(int i = k;i>=0;i--){
        //combine x0+x1+....xcur = k - i
        ll cur;
        cur = mexcur[i+1] > 0 ? nCr(mexcur[i+1]-1+k-i, mexcur[i+1]-1) : 0;
        ans += cur;
        ans %= MOD;
    }
    cout << ans;
}
