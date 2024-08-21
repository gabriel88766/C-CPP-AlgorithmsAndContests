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
    vector<vector<vector<char>>> ch(4, vector<vector<char>>(n, vector<char>(n)));
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cin >> ch[i][j][k];
            }
        }
    }
    vector<int> perm = {0, 1, 2, 3};
    int ans = INF_INT;
    do{
        for(int b0=0;b0<2;b0++){
            int cur = 0;
            for(int i=0;i<4;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        int cb = (b0+i+j+k) % 2;
                        if(cb != ch[perm[i]][j][k] - '0') cur++;
                    }
                }
            }
            ans = min(ans, cur);
        }
    }while(next_permutation(perm.begin(), perm.end()));
    cout << ans << "\n";
}   
