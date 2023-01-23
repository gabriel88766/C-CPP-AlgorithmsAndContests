//Improved, compare hash[0], hash[1] and hash[2]. naturally slower, but still O(1). 
//got AC 5e6 (900ms) in codeforces 7D
//using only 1e9+7 got AC too, 468ms
//others primes 1e9 + ... {103, 123, 181, 207}
// colision probability ~ n^2/(2*10^27) should be less than 0,1%     
// hashing2 to check substrings in an easier way
const int N = 5e6+3;
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