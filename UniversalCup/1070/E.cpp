#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-7;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<double> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    double val, num;
    ll rd;
    for(int i=1;i<=10000;i++){
        double cd = v[0] / i; //i * d = v[0] -> d = v[0] / i
        bool ok = true;
        long long sq = 0;
        for(int j=0;j<n;j++){
            val = v[j] / cd;
            rd = val + 0.01;
            sq += rd * rd;
        }
        double reald = sqrt(sq);
        for(int j=0;j<n;j++){
            val = v[j] / cd;
            rd = val + 0.01;
            num = rd / reald;
            if(abs(num - v[j]) > EPS) ok = false;
        } 
        
        if(ok){
            for(int j=0;j<n;j++){
                val = v[j] / cd;
                rd = val + 0.01;
                cout << rd << "\n";
            }
            break;
        }
    }
}
