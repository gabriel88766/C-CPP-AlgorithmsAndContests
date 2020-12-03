#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<char> is(N,false);

int main(){
int n,aux;
cin >> n;
for(int i=1;i<n;i++){
    cin >> aux;
    is[aux]= true;
}
for(int i=1;i<=n;i++){
    if(!is[i]) cout << i;
}
}
