#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int calc(vector<int> &ans){
    int res = 0;
    for(int i=0;i<ans.size();i++){
        if(i % 2) res |= ans[i];
        else res &= ans[i];
    }
    return res;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 2){
            //end = 3, 1, n-1, n
            vector<bool> used(n+1, false);
            vector<int> ans = {n, n-1, 1, 3};
            used[n] = used[n-1] = used[1] = used[3] = true;
            for(int i=1;i<=n;i++){
                if(!used[i]) ans.push_back(i);
            }
            reverse(ans.begin(), ans.end());
            cout << calc(ans) << "\n";
            assert(calc(ans) == n);
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }else{
            //end based in 31 - clz
            int b = 31 - __builtin_clz(n);
            int aux = (1 << b) - 1;
            vector<int> ans;
            if(aux == 3){ // n = 6
                vector<bool> used(n+1, false);
                ans = {n, aux, aux-1, n-1, 1};
                used[n] = used[aux] = used[aux-1] = used[n-1] = used[1]  = true;
                for(int i=1;i<=n;i++){
                    if(!used[i]) ans.push_back(i);
                }
            }else{
                vector<bool> used(n+1, false);
                ans = {n, aux, aux-1, 3, 1};
                used[n] = used[aux] = used[aux-1] = used[3] = used[1]  = true;
                for(int i=1;i<=n;i++){
                    if(!used[i]) ans.push_back(i);
                }
            }
            reverse(ans.begin(), ans.end());
            cout << calc(ans) << "\n";
            assert(calc(ans) == (n | aux));
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}
