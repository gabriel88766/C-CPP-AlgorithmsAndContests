//Close to TLE, but AC. uncomment Pragma to get better
#include <bits/stdc++.h>
//#pragma GCC target("avx2")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ull bs[3005][47];
ull pot[64];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in", "r", stdin);
    int n;
    cin >> n;
    pot[0] = 1;
    for(int i=1;i<64;i++) pot[i] = pot[i-1] * 2;    
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            if(s[j] == '1'){
                int ind = j/64, jind = j % 64;
                bs[i][ind] |= pot[jind];
            }
        }
    }
    ull ans = 0;
    for(int i=0;i<n;i++){ //O(N^3/64), for N = 3000, about 4*10^8
        for(int j=(i+1);j<n;j++){
            ull cnt = 0;
            int last = (n-1)/64;
            for(int k=0;k<=last;k++){
                cnt += __builtin_popcountll(bs[i][k] & bs[j][k]);
            }
            ans += (cnt * (cnt-1))/2;
        }
    }
    cout << ans;

}
