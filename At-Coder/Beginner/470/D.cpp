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
    vector<int> p(n+1);
    bool rev = false;
    vector<int> pos(n+1);
    for(int i=1;i<=n;i++){
        cin >> p[i];
        pos[p[i]] = i;
    }
    for(int i=1;i<=q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int x, y;
            cin >> x >> y;
            if(rev){
                swap(p[pos[x]], p[pos[y]]);
                swap(pos[x], pos[y]);
            }else{
                swap(p[x], p[y]);
                swap(pos[p[x]], pos[p[y]]);
            }
        }else{
            rev = rev ? false : true;
        }
        
    }
    if(rev){
        for(int j = 1; j <= n; j++) cout << pos[j] << " ";
        cout << "\n";
    }else{
        for(int j = 1; j <= n; j++) cout << p[j] << " ";
        cout << "\n";
    }
    
}
