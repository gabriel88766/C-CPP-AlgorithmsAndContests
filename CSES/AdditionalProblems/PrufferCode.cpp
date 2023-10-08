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
    int n;
    cin >> n;
    vector<int> v(n-2);
    set<int> nu;
    for(int i=0;i<n-2;i++){
        cin >> v[i];
    }
    for(int i=1;i<=n;i++) nu.insert(i);
    vector<pair<int,int>> edgs;
    nu.erase(v[n-3]);
    edgs.push_back({v[n-3], *prev(nu.end())});
    nu.erase(prev(nu.end()));
    for(int i=n-3; i>= 0; i--){
        if(i != 0){
            if(nu.count(v[i-1])){
                edgs.push_back({v[i], v[i-1]});
                nu.erase(v[i-1]);
            }else{
                edgs.push_back({v[i], *prev(nu.end())});
                nu.erase(prev(nu.end()));
            }
        }else{
            edgs.push_back({v[i], *prev(nu.end())});
            nu.erase(prev(nu.end()));
        }
    }

    for(auto x : edgs) cout << x.first << " " << x.second << "\n";
}
