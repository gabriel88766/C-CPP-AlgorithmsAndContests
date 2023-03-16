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
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1), pos;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(i == 1) pos.emplace_back(i);
        else if(v[pos.back()] != v[i]) pos.emplace_back(i);
    }
    pos.emplace_back(n+1);
    for(int i=1;i<=m;i++){
        int a, b, x;
        cin >> a >> b >> x;
        int ind = lower_bound(pos.begin(), pos.end(), a) - pos.begin();

        if(pos[ind] != a){
            if(pos[ind] > b){
                if(v[a] == x) cout << "-1\n";
                else cout << a << "\n";
            }else{
                if(v[pos[ind]] == x) cout << pos[ind]-1 << "\n";
                else cout << pos[ind] << "\n";
            }
        }else{
            if(pos[ind+1] > b){
                if(v[pos[ind]] == x) cout << "-1\n";
                else cout << a << "\n";
            }else{
                if(v[pos[ind]] == x) cout << pos[ind+1] << "\n";
                else cout << a << "\n";
            }
        }
    }
}
