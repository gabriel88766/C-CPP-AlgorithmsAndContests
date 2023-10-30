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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> v1, v2;
    bool ok = true;
    for(int i=0;i<n;i++){
        if(!v1.size() || v1.back() != v[i]) v1.push_back(v[i]);
        else if(!v2.size() || v2.back() != v[i]) v2.push_back(v[i]);
        else{
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "YES\n";
        sort(v2.begin(), v2.end(), greater<int>());
        cout << v1.size() << "\n";
        for(auto x : v1) cout << x << " ";
        cout << "\n";
        cout << v2.size() << "\n";
        for(auto x : v2) cout << x << " ";
        cout << "\n";
    }else cout << "NO\n";
}
