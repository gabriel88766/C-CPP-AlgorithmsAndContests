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
    //freopen("in",  "r", stdin); //test input
    vector<tuple<int, int, int>> add, sub;
    vector<int> eda, eds;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        if(b > a){ add.push_back({a, b, i}); eda.push_back(a); eda.push_back(b);}
        else {sub.push_back({a, b, i}); eds.push_back(a); eds.push_back(b);}
    }
    sort(add.begin(), add.end());
    sort(sub.begin(), sub.end());
    sort(eda.begin(), eda.end());
    sort(eds.begin(), eds.end());
    bool ok = true;
    int mx = -INF_INT;
    for(auto [a, b, j] : add){
        if(b > mx){
            mx = b;
        }else ok = false;
        auto it = lower_bound(eds.begin(), eds.end(), a);
        if(it != eds.end() && *it < b) ok = false;
    }
    mx = -INF_INT;
    for(auto [a, b, j] : sub){
        if(b > mx){
            mx = b;
        }else ok = false;
        auto it = lower_bound(eda.begin(), eda.end(), b);
        if(it != eda.end() && *it < a) ok = false;
    }    
    if(ok){
        cout << "Yes\n";
        for(auto [a, b, j] : sub) cout << j << " ";
        reverse(add.begin(), add.end());
        for(auto [a, b, j] : add) cout << j << " ";
        cout << "\n";
    }else cout << "No\n";
}   
 