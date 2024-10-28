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
    int q;
    cin >> q;
    multiset<int> ms;
    for(int i=0;i<q;i++){
        int tp;
        cin >> tp;
        if(tp == 1){
            int x;
            cin >> x;
            ms.insert(x);
        }else if(tp == 2){
            int x, c;
            cin >> x >> c;
            for(int j=0;j<c;j++){
                auto it = ms.lower_bound(x);
                if(it != ms.end() && *it == x) ms.erase(it);
                else break;
            }
        }else{
            cout << *prev(ms.end()) - *ms.begin() << "\n";
        }
    }
}       
