#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int A[15][15], B[15][15];

vector<int> aux;
void choose(vector<vector<int>> &av, int n, int k){
    if(aux.size() == k){
        av.push_back(aux);
        return;
    }
    int bg = aux.size() ? aux.back() + 1 : 1;
    for(int i=bg; i <= n; i++){
        aux.push_back(i);
        choose(av, n, k);
        aux.pop_back();
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h1, h2, w1, w2;
    cin >> h1 >> w1;
    for(int i=1;i<=h1;i++){
        for(int j=1;j<=w1;j++){
            cin >> A[i][j];
        }
    }
    cin >> h2 >> w2;
    for(int i=1;i<=h2;i++){
        for(int j=1;j<=w2;j++){
            cin >> B[i][j];
        }
    }
    vector<vector<int>> p1, p2;
    choose(p1, h1, h2);
    choose(p2, w1, w2);
    // cout << "Here" << endl;
    bool ok = false;
    for(auto &v1 : p1){
        for(auto &v2 : p2){
            bool cok = true;
            for(int j=0;j<v1.size();j++){
                for(int k=0;k<v2.size();k++){
                    if(A[v1[j]][v2[k]] != B[j+1][k+1]) cok = false;
                }
            }
            if(cok) ok = true;
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}   
