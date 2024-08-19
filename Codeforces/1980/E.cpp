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
        int n, m;
        cin >> n >> m;
        map<int, pair<int, int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;
                cin >> x;
                mp[x] = {i, j};
            }
        }
        bool ok = true;
        vector<int> colo;
        for(int i=0;i<n;i++){
            set<int> ar;
            vector<int> col;
            for(int j=0;j<m;j++){
                int x;
                cin >> x;
                col.push_back(mp[x].second);
                ar.insert(mp[x].first);
            }
            if(ar.size() != 1) ok = false;
            if(i == 0) colo = col;
            else if(colo != col) ok = false;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
