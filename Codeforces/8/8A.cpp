#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    bool fok = false, bok = false;
    string s, seq1,seq2;
    cin >> s >> seq1 >> seq2;
    int k=-1;
    for(int i=0;i<s.size();i++){
        if(s.substr(i, seq1.size()) == seq1) {
            k = i+seq1.size();
            break;
        }
    }
    if(k != -1){
        for(int i=k;i<s.size();i++){
            if(s.substr(i, seq2.size()) == seq2) fok = true;
        }
    }
    reverse(s.begin(), s.end());
    k=-1;
    for(int i=0;i<s.size();i++){
        if(s.substr(i, seq1.size()) == seq1){
            k = i+seq1.size();
            break;
        } 
    }
    if(k != -1){
        for(int i=k;i<s.size();i++){
            if(s.substr(i, seq2.size()) == seq2) bok = true;
        }
    }
    if(fok || bok){
        if(fok && bok) cout << "both";
        else if(fok) cout << "forward";
        else cout << "backward";
    }else cout << "fantasy";
}
