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
        string s;
        int j, k;
        cin >> s >> j >> k;
        string s1, s2;
        for(int i=1;i<=max(j, k); i++){
            if(j == i) s1 = s;
            if(k == i) s2 = s;
            next_permutation(s.begin(), s.end());
        }
        int a1 = 0, a2 = s.size();
        for(int j=0;j<s.size();j++){
            if(s1[j] == s2[j]) a1++;
        }
        a2 -= a1;
        cout << a1 << "A" << a2 << "B\n";
    }
}
