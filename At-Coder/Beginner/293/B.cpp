#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
bool cd[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        if(!cd[i]) cd[aux] = true;
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(!cd[i]) ans.emplace_back(i);
    }
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << " ";
}
