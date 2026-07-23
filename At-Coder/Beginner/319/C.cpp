#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int gr[9];
vector<vector<int>> chk = {
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 4, 8},
    {2, 4, 6}
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;i<9;i++) cin >> gr[i];
    int tt = 0;
    int good = 0;
    vector<int> perm(9);
    for(int j=0;j<9;j++) perm[j] = j;
    do{
        tt++;
        bool ok = true;
        for(auto vec : chk){
            vector<int> ord;
            for(auto x : perm){
                if(x == vec[0] || x == vec[1] || x == vec[2]) ord.push_back(x);
            }
            if(gr[ord[0]] == gr[ord[1]]) ok = false;
        }
        if(ok) good++;
    }while(next_permutation(perm.begin(), perm.end()));
    double ans = good;
    ans /= tt;
    cout << setprecision(15) << fixed << ans << "\n";
}
