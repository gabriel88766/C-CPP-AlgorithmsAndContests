#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string check(int n, int k){
    vector<bool> used(n, false);
    used[0] = true;
    int lst = 0;
    int op;
    if(!(n % 2)){
        op = k + n/2;
        if(op >= n) op -= n;
    }else op = k;
    int hf;
    if(n % 2) hf = 0;
    else hf = n / 2;
    for(int i=1;i<n;i++){
        if(i % 2){
            if(lst == k || lst == op){
                if(!used[k]){
                    lst = k;
                    used[lst] = true;
                }else if(!used[op]){
                    lst = op;
                    used[lst] = true;
                }else return "No";
            }else{
                int dif;
                if(k >= lst) dif = k - lst;
                else dif = n + k - lst;
                int nxt = k + dif;
                if(nxt >= n) nxt -= n;
                if(!used[nxt]){
                    used[nxt] = true;
                    lst = nxt;
                }else return "No";
            }
        }else{
            if(lst == 0 || lst == hf){
                if(!used[0]){
                    lst = 0;
                    used[0] = true;
                }else if(!used[hf]){
                    lst = hf;
                    used[lst] = true;
                }else return "No";
            }else{
                int nxt = n - lst;
                if(!used[nxt]){
                    used[nxt] = true;
                    lst = nxt;
                }else return "No";
            }
        }
    }
    // cout << alln.size() << " " << lst << " -> ";
    return "Yes";
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    // check(19, 14);
    // return 0;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string ans;
        if(n % 4 == 0) ans = "No";
        else if(n % 2 == 1){
            if(gcd(n, k) == 1) ans = "Yes";
            else ans = "No";
        }else{
            if(gcd(n, k) == 1 || gcd(n, k) == 2) ans = "Yes";
            else ans = "No";
        }
        cout << ans << "\n";
    }
}
