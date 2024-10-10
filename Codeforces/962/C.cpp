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
    string s;
    cin >> s;
    int n = s.size();
    int ans = INF_INT;
    for(int i=1;i<(1 << n);i++){
        string chk = "";
        for(int j=0;j<n;j++){
            if(i & (1 << j)) chk += s[j];
        }
        if(chk[0] == '0') continue;
        int rem = n - __builtin_popcount(i);
        int num = stoi(chk);
        int sqt = sqrt(num);
        while(sqt*sqt > num) sqt--;
        while((sqt+1)*(sqt+1) <= num) sqt++;
        if(sqt*sqt == num) ans = min(ans, rem);
    }
    if(ans == INF_INT) ans = -1;
    cout << ans << "\n";
}
