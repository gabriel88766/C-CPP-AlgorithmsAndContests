#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int pi[5000005]; //Lenght of greatest prefix also suffix of substr (0, i) 

//Knuth-Morris-Pratt
void kmp_pre(vector<int> &s){
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    vector<int> patf;
    for(int i=1;i<n;i++){
        patf.push_back(b[i] ^ b[i-1]);
    }
    vector<int> fa;
    for(int i=1;i<n;i++){
        fa.push_back(a[i]^a[i-1]);
    }
    patf.push_back(-1);
    for(auto &x : fa) patf.push_back(x);
    patf.push_back(a[0] ^ a[n-1]);
    for(auto &x : fa) patf.push_back(x);
    patf.pop_back();
    kmp_pre(patf);
    for(int i=n;i<patf.size();i++){
        if(pi[i] == n-1){
            // cout << i << "\n";
            cout << i-2*n+2 << " " << (a[i-2*n+2] ^ b[0]) << "\n";
        }
    }
}
