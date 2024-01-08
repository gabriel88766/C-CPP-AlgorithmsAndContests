#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int a1,a2,a3,b1,b2,b3,n,S1=0,S2=0;
    cin >> n >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    if(b1>(a1+a2)) S1+= (b1-a1-a2);
    if(b2>(a2+a3)) S1+= (b2-a2-a3);
    if(b3>(a3+a1)) S1+= (b3-a3-a1);


    S2+= (min(a1,b2)+min(a2,b3)+min(a3,b1));
    cout << S1 << " " << S2;
}