#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


vector<string> gen(int i){
    if(i == 0){
        vector<string> ans = {"#"};
        return ans;
    }
    vector<string> aux = gen(i-1);
    vector<string> ans(3*aux.size());
    string aux2 = "";
    for(int i=0;i<aux.size();i++) aux2 += '.';
    ll p = 0;
    for(int i=0;i<=2;i++){
        bool t2;
        if(i == 1) t2 = true;
        else t2 = false;
        for(int j=0;j<aux.size();j++){
            if(t2){
                ans[p] = aux[j] + aux2 + aux[j]; 
            }else{
                ans[p] = aux[j] + aux[j] + aux[j];
            }
            p++;
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
    vector<string> ans = gen(n);
    for(auto x : ans){
        cout << x << "\n";
    }
}
