#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f, N = 5e6+3;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
int ds[N]; //degree of string


const int nMOD = 3;
const unsigned long long MOD[] = {(int)1e9+7, (int)1e9+9, (int)1e9+123};
unsigned long long int pot257[N][nMOD];
void init(){
    for(int i=0;i<nMOD;i++) pot257[0][i] = 1;
    for(int i=1;i<N;i++) for(int j=0;j<nMOD;j++) pot257[i][j] = (pot257[i-1][j] * 257) % MOD[j];
}

struct Hash{
    unsigned long long int hash[nMOD];
    int len = 0;
    Hash(){
        for(int i=0;i<nMOD;i++) hash[i] = 0;
    }
    bool isEqual(Hash h){
        for(int i=0;i<nMOD;i++) if(hash[i] != h.hash[i]) return false;
        return true;
    }
    void removeLast(char c){ 
        len--;
        for(int i=0;i<nMOD;i++){
            hash[i] += c * MOD[i];
            hash[i] = (hash[i] - c * pot257[len][i]) % MOD[i];
        }
    }    
    void insertFirst(char c){ //InsertFirst and shift >>
        for(int i=0;i<nMOD;i++){
            hash[i] = (hash[i] * 257);
            hash[i] = (hash[i] + c) % MOD[i];
        }
        len++;
    }
    void insertLast(char c){ 
        for(int i=0;i<nMOD;i++){
            hash[i] =  (hash[i] + c * pot257[len][i]) % MOD[i];
        }
        len++;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    cin >> s;
    ds[0] = 1;
    init();
    Hash h1, h2;
    for(int i=1;i<s.size();i++){
        if((i%2)){
            h1.insertLast(s[i/2]);
            h2.insertFirst(s[i]);
        }else{
            h2.insertFirst(s[i]);
            h2.removeLast(s[i/2]);
        }
        if(h1.isEqual(h2)){
            //cout << i << "\n"; k-palindrome, k > 2
            ds[i] = ds[(i+1)/2-1] + 1;
        }
    }
    ll sum = 0;
    for(int i=0;i<s.size();i++) sum += ds[i];
    cout << sum;

}
