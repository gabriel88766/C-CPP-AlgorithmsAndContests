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
    string s;
    cin >> s;
    string aux = "";
    string aux2 = "";
    for(auto c : s){
        if(c != '1') aux += c;
        else aux2 += c;
    }
    if(aux.size() == 0 || aux[0] == '2'){
        cout << aux2 << aux << "\n";
    }else{
        //aux[0] = '0'
        int ind = -1;
        for(int i=0;i<aux.size();i++){
            if(aux[i] == '2'){
                ind = i;
                break;
            }
        }
        if(ind == -1) cout << aux << aux2 << "\n";
        else{
            cout << aux.substr(0, ind) << aux2 << aux.substr(ind, aux.size()-ind) << "\n";
        }
    }

}
