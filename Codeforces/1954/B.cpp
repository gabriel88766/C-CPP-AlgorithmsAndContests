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
        assert(v[0] == v.back());
        vector<int> aux;
        aux.push_back(-1);
        for(int i=0;i<n;i++){
            if(v[i] != v[0]) aux.push_back(i);
        }
        aux.push_back(n);
        if(aux.size() == 2) cout << "-1\n";
        else{
            int ans = n+1;
            for(int i=1;i<aux.size();i++) ans = min(ans, aux[i] - aux[i-1] - 1);
            cout << ans << "\n";
        }
        
    }
}
