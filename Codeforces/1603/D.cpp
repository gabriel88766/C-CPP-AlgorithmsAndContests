#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+5;

ll dp[18][N]; //from k = 1 to 16
vector<int> divs[N];
int phi[N];
ll sump[N];
void euler(){
    for(ll i=1;i<N;i++) phi[i] = i;
    for(ll i=2; i < N; i++){
        if(phi[i] == i){
            for(ll j = i; j < N; j += i){
                phi[j] -= phi[j]/i; 
            }
        }
    }
    sump[1] = phi[1];
    for(int i=2;i<N;i++){
        sump[i] = sump[i-1] + phi[i];
    }
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            divs[j].push_back(i);
        }
    }
}


//O(kn * log n) * O(C(i, j))
int curi = 1, curj = 1;
ll cans = 1;
ll C(int i, int j){
    while(curj < j){
        curj++;
        for(int x=0;x<divs[curj].size();x++){
            if(divs[curj][x] < curi) continue;
            cans += phi[curj/divs[curj][x]];
        }
    }
    while(curj > j){
        for(int x=0;x<divs[curj].size();x++){
            if(divs[curj][x] < curi) continue;
            cans -= phi[curj/divs[curj][x]];
        }
        curj--;
    }
    while(curi < i){
        cans -= sump[j/curi];
        curi++;
    }
    while(curi > i){
        curi--;
        cans += sump[j/curi];
    }
    return cans;
}

int cur;

void dcdp(int l, int r, int opl, int opr){
    if(l > r) return;
    int m = (l+r)/2;
    int opm = opl;
    ll best = INF_LL; //minimize or maximize?
    for(int u = opl; u <= min(opr, m-1); u++){
        if(best > dp[cur - 1][u] + C(u+1, m)){
            best = dp[cur - 1][u] + C(u+1, m);
            opm = u;
        }
    }
    dp[cur][m] = best;
    dcdp(l, m-1, opl, opm);
    dcdp(m+1, r, opm, opr);
}

void solve(int n, int k){
    //calc();
    for(int i=1;i<=n;i++){
        dp[1][i] = C(1, i);
    }
    for(int i=2;i<=k;i++){
        cur = i;
        dcdp(1, n, i-1, n-1);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("out", "w", stdout); //test input
    euler();
    solve(100000, 16);
    //cerr << "here\n";
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int aux = 1, cnt = 0;
        while(aux <= n){
            aux *= 2;
            cnt++;
        }
        if(cnt <= k) cout << n << "\n";
        else{
            cout << dp[k][n] << "\n";
        }
    }
}
