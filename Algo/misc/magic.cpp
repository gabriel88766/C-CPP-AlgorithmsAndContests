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
__builtin_popcountll(x); //for long long int (ctz, clz)

//some optimizations if needed
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//another
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")
//run locally
//bash -c 'ulimit -s 262144 && ulimit -v 1048576 && time "./a.out"'
//run instead "ulimit -s unlimited" globally