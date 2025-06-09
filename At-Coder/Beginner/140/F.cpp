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
    multiset<int> ms;
    for(int i=1;i<=(1 << n);i++){
        int x;
        cin >> x;
        ms.insert(x);
    }
    vector<int> v;
    v.push_back(*prev(ms.end()));
    ms.erase(prev(ms.end()));
    bool ok = true;
    for(int i=1;i<=n;i++){
        vector<int> nv;
        for(auto &x : v){
            auto it = ms.lower_bound(x);
            if(it == ms.begin()){
                ok = false;
                break;
            }else{
                --it;
                nv.push_back(*it);
                ms.erase(it);
            }
        }
        if(ok == false) break;
        for(auto &x :nv) v.push_back(x);
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
