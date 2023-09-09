#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool func(vector<int> u, vector<int> v){
    return u.size() < v.size();
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> ans(n+1, 0), v(n+1);
    vector<bool> used(n+1, false);
    vector<vector<vector<int>>> comp(n+1);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(i == v[i]){
             ans[i] = i;
             used[i] = true; 
        }
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            vector<int> aux;
            int cur = i;
            do{
                used[cur] = true;
                aux.push_back(cur);
                cur = v[cur];
            }while(cur != i);
            comp[aux.size()].push_back(aux);
        }
    }
    bool ok = true;
    for(int i=0;i<comp.size();i++){
        for(int k = 0; k < comp[i].size(); k++){
            if(i % 2){
                vector<int> aux(i);
                for(int j=0;j<i;j++){
                    aux[(2*j)%i] = comp[i][k][j];
                }
                for(int j=0;j<i;j++){
                    ans[aux[j]] = aux[(j+1)%aux.size()];
                }
            }else{
                if(k+1 < comp[i].size()){
                    vector<int> aux(2*i);
                    for(int j=0;j<i;j++){
                        aux[2*j] = comp[i][k][j];
                        aux[2*j+1] = comp[i][k+1][j];
                    }
                    for(int j=0;j<2*i;j++){
                        ans[aux[j]] = aux[(j+1)%aux.size()];
                    }
                    k++;
                }else{
                    ok = false;
                    break;
                }
            }
        }
    }
    if(ok){
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }else{
        cout << "-1\n";
    }
}
