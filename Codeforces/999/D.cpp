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
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1), mod(m, 0);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<vector<int>> mv(m, vector<int>());
    for(int i=1;i<=n;i++){
         mod[v[i]%m]++;
         mv[v[i]%m].push_back(i);
    }
    int aux=-1, e = n/m;
    if(mod[0] > e && mod[m-1] < e) aux = m-1;
    if(aux != -1){
        for(int i=0;i<(m-1);i++){
            if(mod[i] < e && mod[i+1] > e) aux = i;
        }
    }
    if(aux == -1){
        cout << "0\n";
        for(int i=1;i<=n;i++) cout << v[i] << " ";
    }else{
        vector<int> need;
        ll totaldiff = 0;
        for(int i = m+aux; i>= (aux+1); i--){
            int j = i >= m ? i-m : i;
            if(mod[j] > e){
                for(int k = e+1; k<=mod[j];k++){
                    totaldiff += need.back() - i;
                    v[mv[j].back()] += need.back() - i;
                    mv[j].pop_back();
                    need.pop_back();
                }
            }else if(mod[j] < e){
                for(int k=mod[j]+1;k<=e;k++) need.push_back(i);
            }
        }
        cout << totaldiff << "\n";
        for(int i=1;i<=n;i++) cout << v[i] << " ";
    }
}
