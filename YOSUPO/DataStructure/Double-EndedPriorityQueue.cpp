//Not actually de queue.
//useless, multiset is fast enough
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
    multiset<int> ms;
    int n, q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        ms.insert(x);
    }
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        if(x == 0){
            cin >> x;
            ms.insert(x);
        }else if(x == 1){
            cout << *ms.begin() << "\n";
            ms.erase(ms.begin());
        }else{
            cout << *prev(ms.end()) << "\n";
            ms.erase(prev(ms.end()));
        }
    }
}
