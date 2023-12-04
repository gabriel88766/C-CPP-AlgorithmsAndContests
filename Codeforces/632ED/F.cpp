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
    vector<vector<int>> v(n, vector<int> (n));
    bool ok = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
            if(i == j && v[i][j] != 0) ok = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j] != v[j][i]) ok = false;
        }
    }
    if(!ok){
        cout << "NOT MAGIC\n";
        return 0;
    }
    for(int j=0;j<n;j++){ //j is the collumn 'O'
        vector<pair<int,int>> vp;
        for(int j=0;j<n;j++){
            if(i != j) vp.push_back({v[i][j], j});
        }
        sort(vp.begin(), vp.end());
        //if(vp.back().first == vp[0].first) continue;
        int p = 0;
        for(int j=n-1;j>=0;j--){
            while(p >= 0 && vp[p].first == vp[j].first){
                //do someth with vp[p].second
                p--;
            }
            //check
        }

    }
    if(ok) cout << "MAGIC\n";
    else cout << "NOT MAGIC\n";

}
