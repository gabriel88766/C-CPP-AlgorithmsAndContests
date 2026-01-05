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
    vector<int> rv;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        rv.push_back(x);
        int k = rv.size();
        while(k >= 4 && rv[k-1] == rv[k-2] && rv[k-2] == rv[k-3] && rv[k-3] == rv[k-4]){
            rv.pop_back();
            rv.pop_back();
            rv.pop_back();
            rv.pop_back();
            k = rv.size();
        }
    }
    cout << rv.size() << "\n";
}
