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
    vector<int> ans(s.size(), 0);
    int cur = 0;
    for(int i=0;i<s.size();i++){
        cur += s[i] - '0';
        ans[i] = cur;
    }
    string fn = "";
    for(int i=s.size()-1;i>=1;i--){
        int cur = ans[i];
        fn += (cur % 10) + '0';
        ans[i-1] += cur / 10;
    }
    int aux = ans[0];
    while(aux){
        fn += (aux % 10) + '0';
        aux /= 10;
    }
    reverse(fn.begin(), fn.end());
    cout << fn << "\n";
}
