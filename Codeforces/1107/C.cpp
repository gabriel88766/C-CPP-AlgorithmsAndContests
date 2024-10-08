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
    int n, k;
    string s;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i=0;i<n;i++) cin >> v[i];
    cin >> s;
    s += '%';
    ll ans = 0;
    vector<int> aux;
    char lc = '.';
    for(int i=0;i<=n;i++){
        if(s[i] == lc) aux.push_back(v[i]);
        else{
            lc = s[i];
            sort(aux.begin(), aux.end(), greater<int>());
            for(int j=0;j<min(k, (int)aux.size());j++){
                ans += aux[j];
            }
            aux = {v[i]};
        }
    }
    cout << ans << "\n";
}
