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
    for(int a=1;a<=1000;a++){
        for(int b=a+1;a+b<=1000;b++){
            int c = 1000 - a - b;
            if(c <= b) continue;
            if(a*a + b*b == c*c){
                cout << a*b*c << endl;
            }
        }
    }
}
