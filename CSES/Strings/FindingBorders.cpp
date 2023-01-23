#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int pi[1000005]; //Lenght of greater prefix also suffix

//Knuth-Morris-Pratt
void kmp_pre(string s){
    pi[0] = 0;
    for(int i=1;i<s.size();i++){
        int j = pi[i-1];
        while(j && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    cin >> s;
    kmp_pre(s);
    vector<int> ans;
    int cur = pi[s.size()-1];
    while(cur != 0){
        ans.push_back(cur);
        cur = pi[cur-1];
    }
    reverse(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
}
