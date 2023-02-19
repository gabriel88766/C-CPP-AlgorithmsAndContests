#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in", "w", stdout);
    
    vector<int> perm;
    for(int i=0;i<=3000;i++){
        perm.push_back(0);
        perm.push_back(1);
    }
    cout << 3000 << "\n";
    for(int j=0;j<3000;j++){
        shuffle(perm.begin(), perm.end(), rng);
        for(int k=0;k<3000;k++) cout << perm[k];
        cout << "\n";
    }
}
