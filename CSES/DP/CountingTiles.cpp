//Insane!!
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

// 1 = C, 2 =  C reverse, 3 = U reverse, 4 = U
//counting ok up states.
char aux[] = {'A', 'B', 'C', 'D'};

ll dp[5800], aux2[5800];
int cnt = 0, cntst=0, nst = 0;
int stc[5800], nstc[5800];
vector<string> states;
vector<int> adj[5800];

void cntstates(int n){
    states.push_back("trash"); //1-indexed.
    for(int i=0;i < (1 << (2*n)); i++){
        //decodify all states;
        int x = 3;
        string st;
        for(int j=0;j<n;j++){
            int k = x << (2 * j);
            st += aux[(i & k) >> (2 * j)];
        }
        bool ok = true;
        if(st[0] == 'B') ok = false;
        if(st[n-1] == 'A') ok = false;
        for(int j=0;j<(n-1);j++){
            if(st[j] == 'A' && st[j+1] != 'B') ok = false; //filtering
            if(st[j+1] == 'B' && st[j] != 'A') ok = false;
        }
        if(ok){ //bounds, 5741 of 1048576 (worst case)
            cnt++;
            states.push_back(st);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    cntstates(n);
    for(int i=1;i<=cnt;i++){
        bool ok = true;
        for(int j=0;j<n;j++){
            if(states[i][j] == 'D') ok = false;
        }
        if(ok) dp[i] = 1, stc[++cntst] = i;
    }
    //make that f#@%ing transition graph! only 78243 transitions at most, worst complexity after this 
    // is only 78243 * 1000, so AC.
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=cnt;j++){
            bool ok = true;
            for(int w=0;w<n;w++){
                if((states[i][w] == 'C' && states[j][w] != 'D') || (states[i][w] != 'C' && states[j][w] == 'D')){
                    ok = false;
                    break;
                }
            }
            if(ok) adj[i].push_back(j);
        }
    }

    for(int i=2;i<=m;i++){
        nst = 0;
        vector<bool> isokst(cnt+1, false);
        for(int j=1;j<= cnt; j++) aux2[j] = 0;
        for(int j=1;j<=cntst;j++){
            for(auto u : adj[stc[j]]){
                if(!isokst[u]){
                    nstc[++nst] = u;
                    isokst[u] = true;
                }
                aux2[u] += dp[stc[j]];
            }
        }
        for(int j=1;j<= cnt; j++) dp[j] = aux2[j] % MOD;
        cntst = nst;
        for(int i=1;i<=cntst;i++) stc[i] = nstc[i];
    }

    ll ans = 0;
    for(int i=1;i<=cnt;i++){
        bool ok = true;
        for(int j=0;j<n;j++){
            if(states[i][j] == 'C') ok = false;
        }
        if(ok) ans += dp[i];
    }
    cout << ans % MOD;
}
