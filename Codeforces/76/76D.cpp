#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second

typedef unsigned long long ull;

using namespace std;

ull pow2[64];

void calcpow(){
for(int i=0;i<64;i++){
    pow2[i] = 1;
    pow2[i]<<=i;
}

}
int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
calcpow();
ull A,B,X,Y;
cin >> A >> B;
Y=B;
X=0;
for(int i=63;i>=0;i--){
    ull k = (X^pow2[i])+(Y^pow2[i]);
    if(k<=A && k > (X+Y)){
        X=(X^pow2[i]);
        Y=(Y^pow2[i]);
    }else if(k>=A && k < (X+Y)){
        X=(X^pow2[i]);
        Y=(Y^pow2[i]);
    }
}

if((X+Y)==A) cout << X << " " << Y;
else cout << -1;
}
