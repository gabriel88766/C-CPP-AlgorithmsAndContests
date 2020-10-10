#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< int, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))

using namespace std;

 bool check(par p1,par p2, par p3){
     if(p1.st==p2.st && p1.nd==p2.nd) return false;
     if(p1.st==p3.st && p1.nd==p3.nd) return false;
     if(p2.st==p3.st && p2.nd==p3.nd) return false;
    par l1,l2,l3;
    l1.st = p1.st-p2.st;
    l1.nd = p1.nd-p2.nd;
    l2.st = p3.st-p2.st;
    l2.nd = p3.nd-p2.nd;
    l3.st = p1.st-p3.st;
    l3.nd = p1.nd-p3.nd;
    int result;
    result = l1.st*l2.st + l1.nd*l2.nd;
    if(!result) return true;
    result = l3.st*l2.st + l3.nd*l2.nd;
    if(!result) return true;
    result = l1.st*l3.st + l1.nd*l3.nd;
    if(!result) return true;

    return false;
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int status=0,p;
par l1,l2,l3;
par p1,p2,p3;
cin >> p1.st >> p1.nd >> p2.st >> p2.nd >> p3.st >> p3.nd;
 bool checkT = check(p1,p2,p3);
if(checkT) status = 2;
else{
     checkT = check(mp(p1.st-1,p1.nd),p2,p3);
    if(checkT) status = 1;
      checkT = check(mp(p1.st+1,p1.nd),p2,p3);
    if(checkT) status = 1;
      checkT = check(mp(p1.st,p1.nd-1),p2,p3);
    if(checkT) status = 1;
      checkT = check(mp(p1.st,p1.nd+1),p2,p3);
    if(checkT) status = 1;

       checkT = check(mp(p2.st-1,p2.nd),p1,p3);
    if(checkT) status = 1;
      checkT = check(mp(p2.st+1,p2.nd),p1,p3);
    if(checkT) status = 1;
      checkT = check(mp(p2.st,p2.nd-1),p1,p3);
    if(checkT) status = 1;
      checkT = check(mp(p2.st,p2.nd+1),p1,p3);
    if(checkT) status = 1;

      checkT = check(mp(p3.st-1,p3.nd),p2,p1);
    if(checkT) status = 1;
      checkT = check(mp(p3.st+1,p3.nd),p2,p1);
    if(checkT) status = 1;
      checkT = check(mp(p3.st,p3.nd-1),p2,p1);
    if(checkT) status = 1;
      checkT = check(mp(p3.st,p3.nd+1),p2,p1);
    if(checkT) status = 1;

}
if(status==2) cout << "RIGHT";
else if(status ==1) cout << "ALMOST";
    else cout << "NEITHER";

}
