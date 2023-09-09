#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int pi[100005]; //Lenght of greatest prefix also suffix of substr (0, i) 

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
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size();
    kmp_pre(s);
    vector<int> aux(n+1, 0);
    for(int i=0;i<n;i++){
        if(pi[i] != 0) aux[pi[i]]++;
    }
    aux[n]++;
    for(int i=n;i>=1;i--){
        aux[pi[i-1]] += aux[i];
    }
    vector<int> pos;
    int x = pi[n-1];
    while(x != 0){
        pos.push_back(x);
        x = pi[x-1];
    }
    pos.push_back(n);
    sort(pos.begin(), pos.end());
    cout << pos.size() << "\n";
    for(auto x : pos){
        cout << x << " " << aux[x] << "\n";
    }
}
 