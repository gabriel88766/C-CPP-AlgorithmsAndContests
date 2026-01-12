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
    auto it = max_element(v.begin(), v.end());
    for(int i=0;i<n;i++){
        if(it - v.begin() != i) cout << *it << "\n";
        else{
            int mx = 0;
            if(i != 0){
                auto it1 = max_element(v.begin(), v.begin() + i);
                mx = max(mx, *it1);
            }
            if(i != n-1){
                auto it2 = max_element(v.begin()+i+1, v.end());
                mx = max(mx, *it2);
            }
            cout << mx << "\n";
        }
    }
}
