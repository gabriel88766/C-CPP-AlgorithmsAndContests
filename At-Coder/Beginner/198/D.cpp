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
    string a, b, c;
    cin >> a >> b >> c;
    vector<char> al;
    for(auto x : a) al.push_back(x);
    for(auto x : b) al.push_back(x);
    for(auto x : c) al.push_back(x);
    sort(al.begin(), al.end());
    al.resize(unique(al.begin(), al.end()) - al.begin());
    if(al.size() > 10) cout << "UNSOLVABLE\n";
    else{
        bool ok = false;
        for(int i=0;i<(1 << 10);i++){
            if(__builtin_popcount(i) == al.size()){
                vector<char> cr;
                for(int j=0;j<10;j++) if(i &(1 << j)) cr.push_back(j+'0');
                do{ 
                    vector<char> eqv(26);
                    for(int j=0;j<al.size();j++){
                        eqv[al[j] - 'a'] = cr[j];
                    }
                    string a1, a2, a3;
                    for(auto x : a) a1 += eqv[x-'a'];
                    for(auto x : b) a2 += eqv[x-'a'];
                    for(auto x : c) a3 += eqv[x-'a'];
                    if(a1[0] != '0' && a2[0] != '0' && a3[0] != '0'){
                        if(stol(a1) + stol(a2) == stol(a3)){
                            cout << a1 << "\n" << a2 << "\n" << a3 << "\n";
                            ok = true;
                            break;
                        }
                    }
                }while(next_permutation(cr.begin(), cr.end()));
            }
            if(ok) break;
        }
        if(!ok) cout << "UNSOLVABLE\n";
    }
}
