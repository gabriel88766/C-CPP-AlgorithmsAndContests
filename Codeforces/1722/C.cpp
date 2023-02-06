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
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<string>> v(3, vector<string>(n));
        vector<int> p(3, 0);
        map<string, int> mp;
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                cin >> v[i][j];
                mp[v[i][j]]++;
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                if(mp[v[i][j]] == 1) p[i] += 3;
                if(mp[v[i][j]] == 2) p[i] ++;
            }
        }
        for(int i=0;i<3;i++) cout << p[i] << " ";
        cout << "\n";
    }
}
