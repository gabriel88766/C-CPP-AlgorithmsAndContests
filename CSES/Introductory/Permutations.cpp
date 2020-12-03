#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
cin >> n;
if(n==3 or n==2) cout << "NO SOLUTION";
else if(n==1) cout << 1;
else if(n==4) cout << "2 4 1 3";
else{
    int k=n/2;
    int e=2*k,o;
    if(n%2) o=2*k+1; else o=2*k-1;
    while(e>0){
        cout << e << " ";
        e-=2;
    }
    while(o>0){
        cout << o << " ";
        o-=2;
    }
}

}
