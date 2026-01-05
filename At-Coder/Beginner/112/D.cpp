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
    vector<int> dvs;
    for(int i=1;i*i<=m;i++){
        if(m % i == 0){
            dvs.push_back(i);
            dvs.push_back(m/i);
        }
    }
    sort(dvs.begin(), dvs.end(), greater<int>());
    for(auto x : dvs){
        if(m / x >= n){
            cout << x << "\n";
            break;
        }
    }
}
