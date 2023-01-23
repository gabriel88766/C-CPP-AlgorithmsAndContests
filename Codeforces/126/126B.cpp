//KMP preffix function
#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;


bool isprefsuf[N];
int pi[N];

void kmp_pre(string s){
    pi[0] = 0;
    for(int i=1;i<s.size();i++){
        int j = pi[i-1];
        while(j && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
}

int match = -1;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    int maxpslen = 0;
    cin >> s;
    kmp_pre(s);
    int cur = pi[s.size()-1];
    while(cur != 0){
        isprefsuf[cur] = true;
        cur = pi[cur-1];
    }
    for(int i=1;i<(s.size()-1);i++){
        if(isprefsuf[pi[i]]){
            if(pi[i] > match){
                match = pi[i];
            }
        }  
    }
    if(match!= -1) cout << s.substr(0,match);
    else cout << "Just a legend";
}
