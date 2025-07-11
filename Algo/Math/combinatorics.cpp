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

//quadratic
for(int i=1;i<=2000;i++){
    str[i][1] = str[i][i] = 1;
    for(int j=2;j<i;j++){
        str[i][j] = str[i-1][j-1] + str[i-1][j] * j;
    }
}

//link to generating functions:
//https://www.adamponting.com/some-basic-sequences-generating-functions-and-closed-forms/
//saved in Extra.