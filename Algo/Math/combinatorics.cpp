const int N = 1e7+2; //O(N) preprocessing, O(1) query

//Using Mint
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    assert(a >= b); //catch silly bugs
    return fat[a]*invfat[a-b]*invfat[b];
}

//stirling 2nd kind. n objects, make k partitions
//worth to see https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind (identities)
Mint stirling(ll n, ll k){
    Mint ans = 0;
    for(int i=0;i<=k;i++){
        if((k-i) % 2) ans -= nCr(k, i) * Mint(i).pow(n); 
        else ans += nCr(k, i) * Mint(i).pow(n); 
    }
    return ans*invfat[k];
}