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
        vector<vector<char>> v(3, vector<char>(3));
        for(int i=0;i<3;i++){
            bool okA = false, okB = false, okC = false;
            for(int j=0;j<3;j++){
                cin >> v[i][j];
                if(v[i][j] == 'A') okA = true;
                else if(v[i][j] == 'B') okB = true;
                else if(v[i][j] == 'C') okC = true;
            }
            if(!okA) cout << "A\n";
            else if(!okB) cout << "B\n";
            else if(!okC) cout << "C\n";
        }
    }
}
