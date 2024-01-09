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
        set<pair<int,int>> s;
        for(int i=1;i<=n;i++){
            int aux;
            cin >> aux;
            s.insert({aux, i});
        }
        while(s.size() > 1){
            auto el1 = *s.begin();
            s.erase(s.begin());
            auto el2 = *s.begin();
            s.erase(s.begin());
            el2.first -= el1.first;
            if(el2.first) s.insert({el2.first, el2.second});
        }
        cout << s.begin()->second << "\n";
    }
}
