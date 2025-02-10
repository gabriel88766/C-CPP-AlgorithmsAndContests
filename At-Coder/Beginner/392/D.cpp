#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
const int M = 101;
double d[M][N];
int qd[M];
vector<int> ad[M];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    double ans = 0;
    for(int i=1;i<=n;i++){
        cin >> qd[i];
        for(int j=1;j<=qd[i];j++){
            int x;
            cin >> x;
            ad[i].push_back(x);
            d[i][x]++;
        }
        sort(ad[i].begin(), ad[i].end());
        ad[i].resize(unique(ad[i].begin(), ad[i].end()) - ad[i].begin());
        for(auto &x : ad[i]){
            d[i][x] /= qd[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            double cp = 0;
            for(auto &x : ad[i]){
                cp += d[i][x] * d[j][x];
            }
            ans = max(ans, cp);
        }
    }
    cout << fixed << setprecision(15) << ans << "\n";
}
