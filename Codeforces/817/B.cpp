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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll c1 = 0, c2 = 0, c3 = 0;
    for(int i=0;i<n;i++){
        if(v[i] == v[0]) c1++;
        if(v[i] == v[1]) c2++;
        if(v[i] == v[2]) c3++;
    }
    if(v[1] != v[2]){
        cout << c3 << "\n";
    }else if(v[0] != v[1]){ //v[1] == v[2]
        cout << (c2 * (c2 - 1))/2 << "\n";
    }else{ //both equals
        cout << (c1 * (c1-1) * (c1-2))/6 << "\n";
    }
}
