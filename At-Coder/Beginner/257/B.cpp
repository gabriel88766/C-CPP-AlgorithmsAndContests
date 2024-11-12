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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(k);
    for(int i=0;i<k;i++) cin >> v[i];
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        x--;
        if(v[x] == n) continue;
        else if(x == k-1) v[x]++;
        else if(v[x+1] != v[x] + 1) v[x]++;
    }
    for(int i=0;i<k;i++) cout << v[i] << " ";
    cout << "\n";
}
