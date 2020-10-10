#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int a,b,c,d,e,f,px,py,qx,qy,rx,ry,cont=3;
cin >> a >> b >> c >> d >> e >> f;
px  = c+e-a;
py  = d+f-b;
qx  = c+a-e;
qy  = d+b-f;
rx  = a+e-c;
ry  = b+f-d;

if(px == qx && py == qy){
    cont--;
    if(px == rx && py == ry )
        cont--;
}else{
    if((px == rx && py == ry) || (qx == rx && qy == ry) ) cont--;
}

cout << cont << "\n" << px << " " << py << "\n" << qx  << " " << qy << "\n" << rx << " " << ry;


}

