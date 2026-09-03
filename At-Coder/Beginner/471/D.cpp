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
    int q, v;
    cin >> q >> v;
    multiset<int> ms;
    for(int i=1;i<=q;i++){
        int qr, tq;
        cin >> qr >> tq;
        if(qr == 1){
            int x;
            cin >> x;
            ms.insert(x - tq);
        }else{
            if(ms.size() == 0) cout << "-1\n";
            else{
                auto it = prev(ms.end());
                int val = min(*it + tq, v);
                ms.erase(it);
                cout << val << "\n";
            }
        }
    }
}
