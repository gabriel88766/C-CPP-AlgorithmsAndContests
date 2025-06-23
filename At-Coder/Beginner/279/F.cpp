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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> bx(n+1);
    vector<int> pl(n+1), ipl(n+1);
    vector<int> pli(n+q+1);
    for(int i=1;i<=n;i++) pl[i] = ipl[i] = pli[i] = i;
    int k = n;
    for(int i=1;i<=n;i++) bx[i].push_back(i);
    for(int i=1;i<=q;i++){
        int tq, x, y;
        cin >> tq;
        if(tq == 1){    
            cin >> x >> y;
            swap(x, y);
            if(bx[pl[x]].size() > bx[pl[y]].size()){
                swap(pl[x], pl[y]);
                swap(ipl[pl[x]], ipl[pl[y]]);
            }
            for(auto &xx : bx[pl[x]]){
                bx[pl[y]].push_back(xx);
                pli[xx] = pl[y];
            }   
            bx[pl[x]].clear();
            
        }else if(tq == 2){
            cin >> x;
            bx[pl[x]].push_back(++k);
            pli[k] = pl[x];
        }else{
            cin >> x;
            cout << ipl[pli[x]] << "\n";
        }
        // for(int j=1;j<=n;j++) cout << ipl[pli[j]] << " ";
        // cout << "\n";
    }
}
