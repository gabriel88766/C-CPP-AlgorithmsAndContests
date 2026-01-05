#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-8; 
using namespace std;

double pd[105];
double cw[105];
double dist[205];

bool negative_cycle_bellman(int n, int m){
    bool ch;
    for(int i=0;i<=n;i++) dist[i] = -1e18;
    dist[0] = 0;
    for(int i = 0; i <= n;i++){
        ch = false;
        for(int u = 0; u <= n; u++){
            for(int k = 0; k <= m; k++){
                if(u + m - 2*k >= 0 && u + m - 2 * k <= n && dist[u + m - 2 * k] < dist[u] + cw[k]){
                    dist[u + m - 2 * k] = dist[u] + cw[k];
                    ch = true;
                }
            }
        }
    }
    return ch;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<=n;i++) cin >> pd[i];


    double lo = 0, hi = 1;
    while(hi - lo >= EPS){
        double mid = (lo + hi)/2;
        //check if there is any positive cycle
        for(int i=0; i <= n; i++){
            cw[i] = pd[i] - mid;
        }
        if(negative_cycle_bellman(2*n, n)) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(10) << lo << "\n";
}
