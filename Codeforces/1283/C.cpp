#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<bool> used(n+1, false);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        used[v[i]] = true;
    }
    vector<int> m;
    for(int i=1;i<=n;i++) if(!used[i]) m.push_back(i);
    bool ok = false;
    while(!ok){
        shuffle(m.begin(), m.end(), rng);
        int p = 0;
        bool ok2 = true;
        for(int i=1;i<=n;i++){
            if(!v[i] && m[p++] == i){
                ok2 = false;
                break;
            }
        }
        if(ok2){
            ok = true;
            break;
        }
    }
    int p = 0;
    for(int i=1;i<=n;i++){
        if(v[i]) cout << v[i] << " ";
        else cout << m[p++] << " ";
    }
    cout << "\n";
}
