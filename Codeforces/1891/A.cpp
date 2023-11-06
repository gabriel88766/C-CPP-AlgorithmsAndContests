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
        bool ok = true;
        int lst = 0;
        vector<int> aux, aux2;
        for(int i = 1; (1 << i) <=n; i++){
            lst = i;
            aux.clear();
            for(int j=(1 << (i-1)); j < (1 << i); j++){
                aux.push_back(v[j]);
            }
            aux2 = aux;
            sort(aux2.begin(), aux2.end());
            if(aux != aux2) ok = false;
        }
        aux.clear();
        for(int i=(1 << lst); i < n; i++){
            aux.push_back(v[i]);
        }
        aux2 = aux;
        sort(aux2.begin(), aux2.end());
        if(aux != aux2) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
