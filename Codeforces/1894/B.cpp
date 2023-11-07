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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n), ans(n, 1);
        for(int i=0;i<n;i++) cin >> v[i];
        int cnt = 0;
        vector<bool> used(101, false);
        for(int i=0;i<n;i++){
            if(used[v[i]]) continue;
            for(int j=i+1;j<n;j++){
                if(v[i] == v[j]){
                    if(cnt == 1){
                        ans[j] = 3;
                        used[v[j]] = true;
                        cnt++;
                    }else if(cnt == 0){
                        ans[j] = 2;
                        used[v[j]] = true;
                        cnt++;
                    }
                    break;
                }
            }
        }
        if(cnt == 2) for(auto x : ans) cout << x << " ";
        else cout << "-1";
        cout << "\n";
    }
}
