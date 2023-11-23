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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int ind = min_element(v.begin(), v.end()) - v.begin();
        int mine = v[ind];
        vector<int> aux1;
        for(int i=ind;i<n;i++) aux1.push_back(v[i]);
        auto aux2 = aux1;
        sort(aux2.begin(), aux2.end());
        if(aux1 == aux2) cout << ind << "\n";
        else cout << "-1\n";
    }
}
