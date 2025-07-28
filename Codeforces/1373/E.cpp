#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int get_sum(string s){
    int ans = 0;
    for(auto c : s) ans += c - '0';
    return ans;
}

int gs(int n, int k){
    int sum = 0;
    for(int i=n;i<=n+k;i++){
        sum += get_sum(to_string(i));
    }
    return sum;
}

//for k = 1
string solve(int n){
    if(n % 2){
        if(n <= 17) return to_string(n/2);
        else{
            int x = (n - 17)/2;
            string ans;
            while(x){
                if(x >= 9){
                    ans += '9';
                    x -= 9;
                }else{
                    ans += '0' + x;
                    x = 0;
                }
            }
            reverse(ans.begin(), ans.end());
            ans += '8';
            return ans;
        }
    }else{
        if(n < 10) return "-1";
        else if(n == 10) return "9";
        else{
            int x = n - 9;
            return solve(x) + '9';
        }
    }
}

int s[151][10];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout); //test input
    for(int i=0;i<=150;i++){
        for(int j=0;j<=9;j++){
            s[i][j] = -1;
        }
    }
    for(int i=0;i<=1000000;i++){
        for(int k=2;k<=9;k++){
            if(i >= 100000 && k > 2) continue;
            int ss = gs(i, k);
            if(ss <= 150 && s[ss][k] == -1){
                s[ss][k] = i;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k == 0){
            string ans;
            while(n){
                if(n >= 9){
                    ans += '9';
                    n -= 9;
                }else{
                    ans += '0' + n;
                    n = 0;
                }
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }else if(k == 1){
            cout << solve(n) << "\n";
        }else{
            cout << s[n][k] << "\n";
        }
    }
}
