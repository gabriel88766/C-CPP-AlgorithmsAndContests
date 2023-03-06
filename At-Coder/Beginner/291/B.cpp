#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    double avg;
    int n;
    cin >> n;
    vector<int> v(5*n+1);
    for(int i=1;i<=(5*n);i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=(n+1); i<=(4*n);i++) avg += v[i];
    avg /= (3*n);
    cout << fixed << setprecision(6) << avg;
}
