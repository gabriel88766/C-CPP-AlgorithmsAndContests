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
    int fna=-1, lna;
    for(int i=0;i<s.size();i++){
        if(s[i] != 'a'){
            lna = i;
            if(fna == -1) fna = i;
        }
    }
    
    if(fna != -1){
        string s1 = s.substr(fna, lna-fna+1);
        auto s2 = s1;
        reverse(s2.begin(), s2.end());
        int d1 = fna;
        int d2 = s.size() - lna - 1;
        if(s1 == s2 && d1 <= d2) cout << "Yes\n";
        else cout << "No\n";
    }else cout << "Yes\n";
    
}
