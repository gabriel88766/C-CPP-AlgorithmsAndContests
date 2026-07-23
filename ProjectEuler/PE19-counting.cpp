#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ds[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int ans = 0;
    int cd = 1;
    for(int i=0;i<=100;i++){
        for(int j=0;j<12;j++){
            if(cd == 0 && i != 0) ans++;
            if(j != 1 || i % 4 != 0 || i % 100 == 0 || i % 400 != 0) cd = (cd + ds[j]) % 7;
            else cd = (cd + 29) % 7;
        }
    }
    cout << ans << "\n";
}
