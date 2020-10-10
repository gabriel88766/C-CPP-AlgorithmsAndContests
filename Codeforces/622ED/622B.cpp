#include <bits/stdc++.h>

using namespace std;

int main(){

int H,M,sum,carry;
char ds;
cin >> H >> ds >> M;
cin >> sum;
M+=sum;
carry = M/60;
M%=60;
H+=carry;
H%=24;

printf("%.02d%c%.02d",H,ds,M);

}
