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
    string s;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());
    int ans = 0;
    do{
        bool ok = true;
        for(int i=0;i<=n-k;i++){
            auto cur = s.substr(i, k);
            auto rev = cur;
            reverse(rev.begin(), rev.end());
            if(rev == cur){
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }while(next_permutation(s.begin(), s.end()));
    cout << ans << "\n";
}
