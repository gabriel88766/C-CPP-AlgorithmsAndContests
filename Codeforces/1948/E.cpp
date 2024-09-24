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
        int n, k;
        cin >> n >> k;
        vector<int> gs;
        int aux = n;
        while(aux){
            if(aux >= k) gs.push_back(k);
            else gs.push_back(aux);
            aux = max(aux - k, 0);
        }
        vector<int> cla(n+1, 0);
        vector<int> ans(n+1, 0);
        int ca = 0;
        for(int i=1;i<=n;i+=k){
            ca++;
            int jmx = min(i+k-1, n);
            int sz = jmx - i + 1;
            vector<int> aux;
            for(int i=sz/2;i>=1;i--) aux.push_back(i);
            for(int i=sz;i>sz/2;i--) aux.push_back(i);
            for(int j=i;j<=jmx;j++){
                cla[j] = ca;
                ans[j] = aux[j-i] + (ca - 1) * k;
            }
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
        cout << ca << "\n";
        for(int i=1;i<=n;i++) cout << cla[i] << " ";
        cout << "\n";
    }

}
