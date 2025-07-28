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
    int ans = 0;
    vector<int> v = {6, 10, 15};
    for(int i=16;i<=10000;i++){
        if(i % 10 == 0 || i % 15 == 0 || i % 6 == 0) v.push_back(i);
    }
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << "\n";
}
