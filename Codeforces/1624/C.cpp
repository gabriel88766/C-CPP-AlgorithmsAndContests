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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        if(n == 1){
            cout << "YES\n";
            continue;
        }
        for(int i=0;i<n;i++){
            while(v[i] > n) v[i] /= 2;
        }
        bool ok = true;
        while(true){
            sort(v.begin(), v.end());
            if(v[1] == 1){
                ok = false;
                break;
            }

            //check if ok
            vector<bool> used(n+1, false);
            for(int i=0;i<n;i++){
                if(v[i] <= n) used[v[i]] = true;
            }
            bool nok = false;
            for(int i=1;i<=n;i++){
                if(!used[i]) nok = true;
            }
            if(!nok) break;
            //choose something to half
            int indwr = -1;
            
            for(int i=1;i<n;i++){
                if(v[i] == v[i-1]){
                    indwr = i;
                    break;
                }
            }
            v[indwr] /= 2;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
