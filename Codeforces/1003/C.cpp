#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    double maxv = 0, curv = 0;
    vector<int> ps(n+1);
    ps[0] = 0;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        ps[i] = ps[i-1] + aux;
    }
    for(int i=k; i<=n;i++){
        for(int j=0; j<=n-i; j++){
            curv = ps[j+i] - ps[j];
            curv /= (double) i;
            maxv = max(curv, maxv);
        }
    }
    cout << fixed << setprecision(10) << maxv;
}
