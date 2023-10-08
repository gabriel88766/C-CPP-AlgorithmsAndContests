//dp[i][j] = min(dp[i-1][k] + C[k+1][j]); : k from 1 to j-1
//condition: op[j] is increasing(need to be proved)
//O(kn * log n)
const int N = 3e3+3;
vector<vector<ll>> dp(2, vector<ll>(N));
ll C(int i, int j){
    //some function or precalculated array;
    return (ps[j]-ps[i-1])*(ps[j]-ps[i-1]);
}

void dcdp(int l, int r, int opl, int opr){
    if(l > r) return;
    int m = (l+r)/2;
    int opm = opl;
    ll best = INF_LL; //minimize or maximize?
    for(int u = opl; u <= min(opr, m-1); u++){
        if(best > dp[0][u] + C(u+1, m)){
            best = dp[0][u] + C(u+1, m);
            opm = u;
        }
    }
    dp[1][m] = best;
    dcdp(l, m-1, opl, opm);
    dcdp(m+1, r, opm, opr);
}

void solve(int n, int k){
    for(int i=1;i<=n;i++){
        dp[1][i] = C(1, i);
    }
    for(int i=2;i<=k;i++){
        dp[0] = dp[1];
        dcdp(1, n, i-1, n-1);
    }
}

//834D 1527E 868F