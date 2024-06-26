#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input

    unsigned long long number = 0;
    
    const int inter = 250000;
    double cnt = 0;
    for(int j=0;j<10000000;j++){
        number = 4607182418800017408;
        for(int i=0;i<52;i++){
            int pVal = uniform_int_distribution<int>(0, 1)(rng);
            if(pVal == 1){
                number  |= 1LL << i; 
            }
        }
        double x;
        memcpy(&x, &number, 8);

        x -= 1;
        number = 4607182418800017408;
        for(int i=0;i<52;i++){
            int pVal = uniform_int_distribution<int>(0, 1)(rng);
            if(pVal == 1){
                number  |= 1LL << i; 
            }
        }
        double y;
        memcpy(&y, &number, 8);
        y -= 1;
        if(x*x + y*y <= 1) cnt++;
    }
    cnt /= 2500000;
    cout << fixed << setprecision(15) << cnt;
}
