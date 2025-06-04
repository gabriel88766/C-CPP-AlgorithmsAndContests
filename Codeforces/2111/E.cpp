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
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<vector<int>> tt(3, vector<int>(3, 0));
        auto nd = tt;
        int mv1 = 0, mv2 = 0, aux1 = 0, aux2 = 0;
        for(int i=0;i<q;i++){
            char a, b;
            cin >> a >> b;
            if(a != b) tt[a-'a'][b-'a']++;
            if(a == 'b' && b == 'c') aux2++;
            if(a == 'c' && b == 'b') aux1++;
            if(a == 'b' && b == 'a' && aux1){
                aux1--;
                mv1++;
            }
            if(a == 'c' && b == 'a' && aux2){
                aux2--;
                mv2++;
            }
        }
        for(int i=0;i<n;i++){
            for(char c='a';c<='c';c++){
                if(c == s[i]){
                    cout << c;
                    break;
                }
                nd[s[i]-'a'][c-'a']++;
                //BEGIN CHECK 
                bool ok = true;
                int x = nd[2][1];
                int y = nd[2][0];
                int z = nd[1][0];
                auto aux = tt;
                if(aux[2][1] >= x) {aux[2][1] -= x; x = 0;}
                else {x -= aux[2][1]; aux[2][1] = 0;}
                if(aux[2][0] >= y) {aux[2][0] -= y; y = 0;}
                else {y -= aux[2][0]; aux[2][0] = 0;}
                if(aux[1][0] >=  z) {aux[1][0] -= z; z = 0;}
                else {z -= aux[1][0]; aux[1][0] = 0;}

                if(x) ok = false;
                else if(y && z) ok = false;
                else if(y){
                    if(min(aux[2][1], aux[1][0]) < y || mv1 < y) ok = false;
                }else{
                    if(min(aux[1][2], aux[2][0]) < z || mv2 < z) ok = false;
                }
                //END CHECK
                if(ok){
                    cout << c;
                    break;
                }else nd[s[i]-'a'][c-'a']--;
            }
        }
        cout << "\n";

    }
}
