#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = (1 << 16) + 3;
ll fat[N], invfat[N];

void init(){ //MOD must be prime
    fat[0] = invfat[N-1]  = 1;
    for(int i=1;i<N;i++){
        fat[i] = (fat[i-1]*i)%MOD;
    }
    ll aux1 = MOD-2, aux2 = fat[N-1];
    while(aux1){
        if(aux1 & 1) invfat[N-1] = (invfat[N-1]*aux2)%MOD;
        aux2 = (aux2 * aux2) % MOD;
        aux1 >>= 1;
    }
    for(int i=N-2;i>=0;i--) invfat[i] = (invfat[i+1] * (i + 1))%MOD;
}
ll nCr(ll a, ll b){
    if(b < 0) return 0;
    if(b > a) return 0;
    return (((fat[a]*invfat[a-b])%MOD)*invfat[b])%MOD;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> v(1 << n);
    init();
    int cnt = 0;
    for(int i=0;i<(1<<n);i++){
         cin >> v[i];
         if(i && v[i] < v[0]) cnt++;
    }
    ll ans = 1; 
    if(k == (n+1)){
        if(cnt == ((1 << n)-1)) cout << fat[1 << n] << "\n";
        else cout << "0\n";
    }else{
        if(cnt == ((1 << n)-1)) cout << "0\n";
        else if(cnt < ((1 << (k-1))-1)) cout << "0\n";
        else{
            //de cnt eu escolho 2^(k - 1) para caixa 1
            ans = (ans * nCr(cnt, ((1 << (k-1))-1)))% MOD;
            //escolher 2^(k-1) restantes, de forma que não sejam todos menores que Juquinha
            //basta subtrair de todas as escolhas as escolhas que todos são menores que juq.
            ll x = nCr((1 << n) - (1 << (k-1)), 1 << (k-1)) - nCr(cnt - ((1 << (k-1))-1), 1 << (k-1));
            if(x < 0) x += MOD;
            ans = (ans * x) % MOD;
            ans = (ans * fat[1 << (k-1)]) % MOD; //caixa 1 com 2^(k-1) permuta
            ans = (ans * fat[1 << (k-1)]) % MOD; //caixa 2 com 2^(k-1) permuta
            ans = (ans * fat[(1 << n) - (1 << k)]) % MOD; //caixa 3 com 2^n - 2^k, permuta
            ans = (ans * (1 << (n-k+1))) % MOD; //onde colocar a caixa
            cout << ans << "\n";
        }
    }
}
