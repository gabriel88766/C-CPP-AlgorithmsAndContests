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
    cin >> n >> k;
    k = n-k;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        cin >> ans[i];
    }
    for(int i=0;i<18;i++){
        if(k & (1<< i)){
            int jp = 1 << i;
            vector<int> nans;
            for(int j=0;j<ans.size()-jp;j++){
                nans.push_back(ans[j] ^ ans[j+jp]);
            }
            ans = nans;
        }
    }
    for(auto &x : ans) cout << x << " ";
    cout << "\n";
}
