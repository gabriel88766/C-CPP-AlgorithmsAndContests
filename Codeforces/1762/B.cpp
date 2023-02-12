#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int pot[31];
void init(){
    pot[0] = 1;
    for(int i=1;i<31;i++) pot[i] = pot[i-1] << 1;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    init();
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> ans;
        for(int i=1;i<=n;i++){
            int aux;
            cin >> aux;
            int bp = 0;
            while(pot[bp] < aux) bp++;
            if(aux < pot[bp]) ans.push_back({i, pot[bp] - aux});
        }
        cout << ans.size() << "\n";
        for(auto u : ans) cout << u.first << " " << u.second << "\n";
    }
}
