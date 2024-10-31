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
    string num, x;
    cin >> num >> x;
    reverse(num.begin(), num.end());
    reverse(x.begin(), x.end());
    vector<int> dp = {1, 0, 0, 0, 0, 0, 0};
    int cg = 1;
    for(int i=0;i<n;i++){
        auto ndp = dp;
        int cn = (num[i] - '0') % 7;
        cn = (cn * cg) % 7;
        cg = (cg * 10) % 7;
        if(cn == 0) continue;
        if(x[i] == 'T'){
            for(int j=0;j<7;j++){
                if(dp[j]){
                    int ocg = (7 - cn + j) % 7;
                    ndp[ocg] = 1;
                }
            }
        }else{
            for(int j=0;j<7;j++){
                if(!dp[j]){
                    int ocg = (7 - cn + j) % 7;
                    ndp[ocg] = 0;
                }
            }
        }
        dp = ndp;
    }
    if(dp[0]) cout << "Takahashi\n";
    else cout << "Aoki\n";
}
