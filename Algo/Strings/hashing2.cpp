//is O(N) but high constant
/*Some primes
1000000007 1000000009 1000000021 1000000033 1000000087
1000000093 1000000097 1000000103 1000000123 1000000181 
1000000207 1000000223 1000000241 1000000271 1000000289 
1000000297 1000000321 1000000349 1000000363 1000000403 
1000000409 1000000411 1000000427 1000000433 1000000439 
1000000447 1000000453 1000000459 1000000483 1000000513 
1000000531 1000000579 1000000607 1000000613 1000000637 
1000000663 1000000711 1000000753 1000000787 1000000801 
1000000829 1000000861 1000000871 1000000891 1000000901 
1000000919 1000000931 1000000933 1000000993 */
const int N = 1e6+10;
const int nMOD = 1; //change nMOD if needed;
ull pVal; 
const ull MOD[] = {(ull)1e9+7, (ull)1e9+9, (ull)1e9+21, (ull)1e9+33, (ull)1e9+87, (ull)1e9+93, (ull)1e9+97};
ull pot[N][nMOD];
ull invpot[N][nMOD];
char inited = false;

ull binpow(ull a, ull b, ull m){
    ull ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

void init(int n){
    inited = true;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    pVal = uniform_int_distribution<int>(257, 1000000000)(rng); //greater than alphabet
    for(int i=0;i<nMOD;i++){
        pot[0][i] = 1, pot[1][i] = pVal;
        invpot[0][i] = 1, invpot[1][i] = binpow(pVal, MOD[i]-2, MOD[i]);
    }  
    for(int i=2;i<n;i++) 
        for(int j=0;j<nMOD;j++){
            pot[i][j] = (pot[i-1][j] * pVal) % MOD[j]; 
            invpot[i][j] = (invpot[i-1][j] * invpot[1][j]) % MOD[j];
        } 
}

struct Hash{ //1-indexed
    vector<vector<ull>> hash;
    int len = 0;
    void inithash(int maxl, int strlen){
        if(!inited) init(maxl);
        hash.assign(strlen+1, vector<ull> (nMOD, 0));
    }
    Hash(string &s, int maxlen, int strlen){ // maxlen > nmax
        inithash(maxlen, strlen);
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<nMOD;j++){
                hash[i][j] = (hash[i-1][j] + pot[i-1][j] * s[i-1]) % MOD[j];
            }
        }
        len = s.size();
    }
    ull *subHash(ull *ans, int l, int r){ //O(1)
        for(int i=0;i<nMOD;i++) ans[i] = ((hash[r][i]-hash[l-1][i]+MOD[i]) * invpot[l-1][i]) % MOD[i];
        return ans;
    }
    void pop_back(){ 
        for(int i=0;i<nMOD;i++){
            hash[len][i] = 0;
        }
        len--;
    }
    void push_back(char c){
        len++; 
        for(int i=0;i<nMOD;i++){
            hash[len][i] =  (hash[len-1][i] + c * pot[len][i]) % MOD[i];
        }
    }
};


bool isEqual(ull *h1, ull *h2){
    for(int i=0;i<nMOD;i++) if(h1[i] != h2[i]) return false;
    return true;
}