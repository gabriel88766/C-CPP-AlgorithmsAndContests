#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+1;
const int M = 20;
int jm1[N][M], jm2[N][M];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int lo = 1, hi = 0;
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1), ps(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ps[i] = ps[i-1] + v[i];
    }
    hi = ps[n] / k;
    while(lo != hi){
        int mid = lo + (hi - lo + 1) / 2;
        //make the graph
        for(int i=1;i<=n;i++){
            if(ps[n] - ps[i-1] < mid){
                jm2[i][0] = 1;
                int aux = ps[n] - ps[i-1];
                int x = 0;
                for(int j=n/2;j>=1;j>>=1){
                    while(x + j <= n && ps[x+j] < mid - aux) x += j;
                }
                x++;
                jm1[i][0] = x+1;
            }else{
                //find x
                int x = i-1;
                for(int j=n/2;j>=1;j>>=1){
                    while(x + j <= n && ps[x+j] - ps[i-1] < mid) x += j;
                }
                x++;
                //sum from i to x >= mid
                if(x == n){
                    jm1[i][0] = 1;
                    jm2[i][0] = 1;
                }else{
                    jm1[i][0] = x + 1;
                    jm2[i][0] = 0;
                }
            }
        }
        for(int i=1;i<M;i++){
            for(int j=1;j<=n;j++){
                jm1[j][i] = jm1[jm1[j][i-1]][i-1];
                jm2[j][i] = jm2[j][i-1] + jm2[jm1[j][i-1]][i-1];
            }
        }
        bool ok = false;
        for(int i=1;i<=n;i++){
            //check i after k
            int d = i;
            int jmp = 0;
            for(int j=0;j<M;j++){
                if(k & (1 << j)){
                    jmp += jm2[d][j];
                    d = jm1[d][j];
                }
            }
            if(jmp == 0 || jmp == 1 && d <= i) ok = true;
        }
        if(ok) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << " ";
    //now 2nd part
    int ans = 0;
    vector<bool> vis(n+1, false);
    for(int i=1;i<=n;i++){
        if(ps[n] - ps[i-1] < lo){
            jm2[i][0] = 1;
            int aux = ps[n] - ps[i-1];
            int x = 0;
            for(int j=n/2;j>=1;j>>=1){
                while(x + j <= n && ps[x+j] < lo - aux) x += j;
            }
            x++;
            jm1[i][0] = x+1;
        }else{
            //find x
            int x = i-1;
            for(int j=n/2;j>=1;j>>=1){
                while(x + j <= n && ps[x+j] - ps[i-1] < lo) x += j;
            }
            x++;
            //sum from i to x >= mid
            if(x == n){
                jm1[i][0] = 1;
                jm2[i][0] = 1;
            }else{
                jm1[i][0] = x + 1;
                jm2[i][0] = 0;
            }
        }
    }
    for(int i=1;i<M;i++){
        for(int j=1;j<=n;j++){
            jm1[j][i] = jm1[jm1[j][i-1]][i-1];
            jm2[j][i] = jm2[j][i-1] + jm2[jm1[j][i-1]][i-1];
        }
    }
    bool ok = false;
    for(int i=1;i<=n;i++){
        //check i after k
        int d = i;
        int jmp = 0;
        for(int j=0;j<M;j++){
            if(k & (1 << j)){
                jmp += jm2[d][j];
                d = jm1[d][j];
            }
        }
        if(jmp == 0 || jmp == 1 && d <= i);
        else ans++;
    }
    cout << ans << "\n";
}
