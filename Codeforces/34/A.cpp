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
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int minans = 1001, ind1, ind2;
    for(int i=0;i<n;i++){
        if(abs(v[(i+1)%n] - v[i]) < minans){
            minans = abs(v[(i+1)%n] - v[i]);
            ind1 = i+1;
            ind2 = ((i+1)%n)+1;
        }
    }
    cout << ind1 << " " << ind2 << "\n";
}
