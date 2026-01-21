#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 805;
int gr[N][N];
int ps[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
        }
    }
    int lo = 0, hi = 1000000000;
    while(lo != hi){
        int mid = lo + (hi - lo)/2;
        bool ok = false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ps[i][j] = gr[i][j] <= mid ? 1 : -1;
                ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
                if(i >= k && j >= k && ps[i][j] - ps[i-k][j] - ps[i][j-k] + ps[i-k][j-k] >= 0) ok = true;
            }
        }
        //if ok, then there is at least 1 square
        if(ok) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}
