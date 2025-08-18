#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 100001;
int p[N]; // 0 if prime, 1 if not prime
int np[N];
int cnt[N];
void sieve(){
    p[1] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            cnt[i] = 1;
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
        }
        cnt[i] += cnt[i-1];
    }
    int val = INF_INT;
    for(int i=N-1;i>=0;i--){
        np[i] = val;
        if(!p[i]) val = i;
    }
}

char vx[8][8];
int ans = 0, n;
int sz = 0;

int bruteforce(){
    int ans = 0;
    int fst = 0;
    for(int j=0;j<sz;j++) fst = 10*fst + vx[j][sz];
    int nx = 1;
    for(int j=0;j<n-sz;j++){
        nx *= 10;
        fst *= 10;
    }
    int lst = fst + nx;
    if(sz == n-1) return cnt[lst] - cnt[fst];
    fst = np[fst];

    while(fst < lst){
        int aux = fst;
        for(int j=n-1;j>=0;j--){
            vx[sz][j] = (aux % 10);
            aux /= 10;
        }
        vx[sz][n] = 0;
        sz++;
        ans += bruteforce();
        sz--;
        fst = np[fst];
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int t;
    cin >> t;
    while(t--){
        string px;
        cin >> px;
        for(int j=0;j<px.size();j++) vx[0][j] = px[j] - '0';
        sz = 1;
        n = px.size();
        cout << bruteforce() << "\n";
    }
}
