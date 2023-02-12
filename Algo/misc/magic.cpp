//all submasks of a given mask in O(3^n)
for (int m=0; m<(1<<n); ++m){
    for (int s=m; s; s=(s-1)&m){ 
        //do something
    }
}
//count leading and trailling zeroes and quantity of ones., both fast O(1)
x = 6; //00000000 00000000 00000000 00000110
__builtin_clz(x); //29
__builtin_ctz(x); //1
__builtin_popcount(x); //2
__builtin_popcountll(x); //for long long int