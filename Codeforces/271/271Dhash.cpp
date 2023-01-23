//bad solution, O(n log n), almost TLE(1700ms of 2000)
#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
const int N = 1505;
const int nMOD = 3, pVal = 257;

const unsigned long long MOD[] = {(int)1e9+7, (int)1e9+9, (int)1e9+123};
unsigned long long int pot[N][nMOD];
char inited = false;
void init(){
    inited = true;
    for(int i=0;i<nMOD;i++) pot[0][i] = 1;
    for(int i=1;i<N;i++) for(int j=0;j<nMOD;j++) pot[i][j] = (pot[i-1][j] * pVal) % MOD[j];
}

struct Hash{ //dont support substrings yet.
    unsigned long long int hash[nMOD];
    int len = 0;
    Hash(){
        if(!inited) init();
        for(int i=0;i<nMOD;i++) hash[i] = 0;
    }
    Hash(string s){ //not tested
        Hash();
        for(int i=0;i<s.size();i++){
            for(int j=0;j<nMOD;j++){
                hash[j] = (hash[j] + pot[i][j] * s[i]) % MOD[j];
            }
        }
        len = s.size();
    }
    void concat(string s){ //not tested
        for(int i=0;i<s.size();i++){
            for(int j=0;j<nMOD;j++){
                hash[j] = (hash[j] + pot[i+len][j] * s[i]) % MOD[j];
            }
        }
        len += s.size();
    }
    bool isEqual(Hash h){
        for(int i=0;i<nMOD;i++) if(hash[i] != h.hash[i]) return false;
        return true;
    }
    void removeLast(char c){ //removeFirst needs modular division, O(log n) or some other shift strategy
        len--;
        for(int i=0;i<nMOD;i++){
            hash[i] += c * MOD[i]; //anti "overflow"
            hash[i] = (hash[i] - c * pot[len][i]) % MOD[i];
        }
    }    
    void insertFirst(char c){ //InsertFirst and shift >>
        for(int i=0;i<nMOD;i++){
            hash[i] = (hash[i] * pVal);
            hash[i] = (hash[i] + c) % MOD[i];
        }
        len++;
    }
    void insertLast(char c){ 
        for(int i=0;i<nMOD;i++){
            hash[i] =  (hash[i] + c * pot[len][i]) % MOD[i];
        }
        len++;
    }
};

set<unsigned long long int> hashs;
bool isGood[256];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s, g;
    int cnt=0, k;
    cin >> s >> g >> k;
    for(int i=0;i<26;i++){
        isGood[i+'a'] = g[i] - '0';
    }
    for(int i=0;i<s.size();i++){
        Hash h;
        cnt = 0;
        for(int j=i;j<s.size();j++){
            if(isGood[s[j]]){
                h.insertLast(s[j]);
                hashs.insert(h.hash[1]*h.hash[0]);
            }else if(cnt < k){
                cnt++;
                h.insertLast(s[j]);
                hashs.insert(h.hash[1]*h.hash[0]);
            }else break;
        }
    }
    cout << hashs.size();
}
