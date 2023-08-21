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
        sort(v.begin(), v.end());
        if(v[0] != v.back()){
            int ind = 0;
            while(v[0] == v[ind]) ind++;
            cout << ind << " " << n-ind << "\n";
            for(int i=0;i<ind;i++) cout << v[i] << " ";
            cout << "\n";
            for(int i=ind;i<n;i++) cout << v[i] << " ";
            cout << "\n";
        }else cout << "-1\n";
    }
}
