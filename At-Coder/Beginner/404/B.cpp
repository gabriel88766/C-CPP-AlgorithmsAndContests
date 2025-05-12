#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void rotate(vector<vector<char>> &gr){
    //gr[j][n-i-1] = gr[i][j];
    vector<vector<char>> ng = gr;
    int n = gr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ng[j][n-i-1] = gr[i][j];
        }
    }
    gr = ng;
}

int cnt_dif(vector<vector<char>> &ga, vector<vector<char>> &gb){
    int ans = 0;
    for(int i=0;i<ga.size();i++){
        for(int j=0;j<ga[i].size();j++){
            if(ga[i][j] != gb[i][j]) ans++;
        }
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<vector<char>> ga(n, vector<char>(n));
    auto gb = ga;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> ga[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> gb[i][j];
        }
    }
    int ans = cnt_dif(ga, gb);
    for(int i=1;i<=3;i++){
        rotate(ga);
        ans = min(ans, cnt_dif(ga, gb) + i);
    }
    cout << ans << "\n";
}
