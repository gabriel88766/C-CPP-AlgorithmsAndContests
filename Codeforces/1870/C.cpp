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
        vector<vector<int>> c(k+1);
        vector<int> v(n+1);
        for(int i=0;i<n;i++){
            cin >> v[i];
            c[v[i]].push_back(i);
        }
        set<int> s;
        for(int i=0;i<n;i++) s.insert(i);
        for(int i=1;i<=k;i++){
            if(c[i].size()){
                //int lh = c[i][0], rh = c[i].back();
                int l, r;
                l = *s.begin();
                r = *prev(s.end());
                for(auto x : c[i]) s.erase(x);
                //cout << lh << " " << rh << " " << lv << " " << rv << "\n";
                cout << 2*(r-l+1) << " ";
            }else cout << "0 ";
        }
        cout << "\n";
    }
}
