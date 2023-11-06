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
    bool ok = true;
    vector<vector<int>> v(9, vector<int>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> v[i][j];
        }
    }
    for(int i=0;i<9;i++){
        //check row i
        set<int> s;
        for(int j=0;j<9;j++){
            s.insert(v[i][j]);
        }
        if(s.size() != 9) ok = false;
    }
    for(int j=0;j<9;j++){
        //check collumn j
        set<int> s;
        for(int i=0;i<9;i++){
            s.insert(v[i][j]);
        }
        if(s.size() != 9) ok = false;
    }
    for(int i=0;i<9; i += 3){
        for(int j=0;j<9;j+=3){
            //square begin in i, j
            set<int> s;
            for(int u=0;u<3;u++){
                for(int w=0;w<3;w++){
                    s.insert(v[i+u][j+w]);
                }
            }
            if(s.size() != 9) ok = false;
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
