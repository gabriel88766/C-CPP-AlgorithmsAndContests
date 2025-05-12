#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e3+3;
string nb[N];
string fc[N];
string exps[N];
string trm[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    nb[1] = "1", nb[11] = "11", nb[111] = "111", nb[1111] = "1111";
    for(int i=1;i<N;i++){
        /*
        if(fc[i].size()) trm[i] = fac[i];
        if(trm[i].size()) exp[i] = trm[i];*/
        //try to make expr
        for(int j=2;j<i;j++){
            if(i % j) continue;
            if(trm[i/j].size() + 1 + fc[j].size() < trm[i].size() || trm[i].size() == 0){
                trm[i] = trm[i/j] + '*' + fc[j];
            }
        }
        for(int j=1;j<i;j++){
            if(exps[j].size() + trm[i-j].size() + 1 < exps[i].size() || exps[i].size() == 0){
                exps[i] = exps[j] + '+' + trm[i-j];
            }
        }
        if(nb[i].size()) fc[i] = nb[i];
        if(fc[i].size() &&(trm[i].size() > fc[i].size() || fc[i].size() == 0)) trm[i] = fc[i];
        if(trm[i].size() && exps[i].size() > trm[i].size()) exps[i] = trm[i];
        if(fc[i].size() > exps[i].size() + 2 || fc[i].size() == 0) fc[i] = '(' + exps[i] + ')';
        if(trm[i].size() == 0 || trm[i].size() > fc[i].size()) trm[i] = fc[i];
        if(exps[i].size() == 0 || exps[i].size() > trm[i].size()) exps[i] = trm[i];
    }
    int n;
    cin >> n;
    cout << exps[n] << "\n";
    
}
