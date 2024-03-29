#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    double p = 0;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        double curp = 1/(double)n;
        double mtp = 1;
        int cnt = 0, aux = i;
        while(aux < k){
            cnt++;
            aux *= 2;
            mtp /= 2;
        }
        p += mtp*curp;
    }
    cout << fixed << setprecision(15) << p;
}
