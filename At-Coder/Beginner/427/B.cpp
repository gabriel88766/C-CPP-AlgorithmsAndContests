#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int f[101];
int sdig(int num){
    int ans = 0;
    while(num){
        ans += num % 10;
        num /= 10;
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    f[0] = 1;
    for(int i=1;i<=100;i++){
        int ans = 0;
        for(int j=0;j<i;j++) ans += sdig(f[j]);
        f[i] = ans;
    }
    int n;
    cin >> n;
    cout << f[n] << "\n";
}
