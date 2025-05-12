#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 31;
int n, t, m, k;
double dp[N][N];
vector<vector<int>> allp;
vector<int> cur;
int sum = 0;
void gen_all(){
    if(sum == m){
        if(cur.size() <= n) allp.push_back(cur);
        return;
    }else if(sum > m) return;

    for(int i=1;i<=(cur.size() ? cur.back() : m); i++){
        cur.push_back(i);
        sum += i;
        gen_all();
        sum -= i;
        cur.pop_back();
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> t >> m >> k;
    gen_all();
    for(int i=0;i<=t;i++) dp[k][i] = 1;
    for(int i=k-1;i>=0;i--){
        dp[i][0] = 0;
        for(int j=1;j<=t;j++){
            dp[i][j] = 0;
            for(auto &v : allp){
                double curs = 0;
                for(auto &x : v){
                    curs += (1.0/n) * dp[min(i+x, k)][j-1];
                }
                curs += (((n - v.size()) * 1.0)/n) * dp[i][j-1];
                dp[i][j] = max(dp[i][j], curs);
            }
        }
    }
    cout << fixed << setprecision(15)  << dp[0][t] << "\n";
}
