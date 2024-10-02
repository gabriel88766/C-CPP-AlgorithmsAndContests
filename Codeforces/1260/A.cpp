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
    int n;
    cin >> n;
    //unnecessary crazy brute force :)
    // 10^3 * 10^4
    while(n--){
        int c1, sum;
        cin >> c1 >> sum;
        vector<int> vx(c1, 1);
        int ans = 0;
        for(int i=0;i<sum;i++){
            ans += vx[i%c1];
            vx[i%c1] += 2;
        }
        cout << ans << "\n";
    }
}
