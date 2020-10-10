#include <bits/stdc++.h>
using namespace std;

int pow2[] = { 2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,65536*2,65536*4,65536*8,65536*16,65536*32,65536*64,65536*128,65536*256,65536*512,65536*1024,65536*2048,65536*4096,65536*8192,65536*16384};

int main(){
int n,aux,lower,upper;
long long int qnt = 0;
vector<int> v;
vector<int>::iterator low,up;
cin >> n;
for(int i=0;i<n;i++){
    cin >> aux;
    v.push_back(aux);
}
sort(v.begin(),v.end());
for(int i=1;i<v.size();i++){
    int k = v[i-1];
    for(int j=0;j<30;j++){
        if(pow2[j]>k){
            low = lower_bound (v.begin()+i, v.end(), pow2[j]-k);
            up  = upper_bound (v.begin()+i, v.end(), pow2[j]-k);
            lower = (low- v.begin());
            upper = (up - v.begin());
            qnt+=(upper-lower);
        }
    }
}
cout << qnt;
}


/*
1 2 3 7

*/
