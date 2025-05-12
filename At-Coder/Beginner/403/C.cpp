#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+2;
bool alw[N];
set<int> st[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1;i<=q;i++){
        int tq, x, y;
        cin >> tq;
        if(tq == 1){
            cin >> x >> y;
            st[x].insert(y);
        }else if(tq == 2){
            cin >> x;
            alw[x] = true;
        }else{  
            cin >> x >> y;
            if(alw[x]) cout << "Yes\n";
            else if(st[x].count(y)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
