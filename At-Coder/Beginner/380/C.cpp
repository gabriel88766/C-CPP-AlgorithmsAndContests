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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> bl;
    bool fl = false;
    for(int i=0;i<s.size();i++){
        if(s[i] == '1'){
            if(!fl){
                bl.push_back(i);
                fl = true;
            }
        }else{
            fl = false;
        }
    }
    int aux = bl[k-1];
    while(aux-1 >= 0 && s[aux - 1] == '0') aux--;
    int aux2 = bl[k-1];
    if(aux != aux2){
        while(aux2 < n && s[aux2] == '1'){
            swap(s[aux], s[aux2]);
            aux++;
            aux2++;
        }
    }
    cout << s << "\n";
}
