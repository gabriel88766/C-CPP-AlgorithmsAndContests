#include <bits/stdc++.h>
using namespace std;

#define BUFSIZE 50000000

size_t rdsz, wrsz = 0, crdsz = 0;
char rdbuff[BUFSIZE];
char wrbuff[BUFSIZE];
char auxbuff[BUFSIZE];

inline void readall(){
    rdsz = read(0, rdbuff, BUFSIZE);
}

inline void writeall(){
    write(1, wrbuff, wrsz);
}

inline void moveblank(){
    char c;
    while(true){
        c = rdbuff[crdsz];
        if(c==' '||c=='\n'||c=='\r'||c=='\t'||c=='\v'||c=='\f') crdsz++;
        else break;
    }
}

inline long long nextll(){
    moveblank();
    bool neg = false;
    if (rdbuff[crdsz] == '-') { neg = true; crdsz++; }
    long long ans = 0;
    while(rdbuff[crdsz] >= '0' && rdbuff[crdsz] <= '9'){
        ans *= 10;
        ans += rdbuff[crdsz++] - '0';
    }
    return neg ? -ans : ans;
}

inline int nextint(){
    moveblank();
    bool neg = false;
    if (rdbuff[crdsz] == '-') { neg = true; crdsz++; }
    int ans = 0;
    while(rdbuff[crdsz] >= '0' && rdbuff[crdsz] <= '9'){
        ans *= 10;
        ans += rdbuff[crdsz++] - '0';
    }
    return neg ? -ans : ans;
}

inline int nextchar(){
    moveblank();
    return rdbuff[crdsz++];
}

inline void writell(long long c){
    if(c == 0) wrbuff[wrsz++] = '0';
    else{
        size_t csz = 0;
        if(c < 0){
            wrbuff[wrsz++] = '-';
            c = -c;
        }
        while(c){
            auxbuff[csz++] = c % 10;
            c /= 10;
        }
        while(csz){
            wrbuff[wrsz++] = auxbuff[--csz] + '0';
        }
    }
}

inline void newspace(){
    wrbuff[wrsz++] = ' ';
}
inline void newline(){
    wrbuff[wrsz++] = '\n';
}

//cout << fixed << setprecision(6)
int main(){
    // freopen("in", "r", stdin);
    readall();
    long long a, b, c; 
    int q;
    q = nextint();
    for(int i=1;i<=q;i++){
        a = nextll(), b = nextll();
        c = a + b;
        writell(c);
        newline();
    }
    writeall();
    return 0;
}
