//iterate over ceils
while(true){
    //do something with cx;
    ll lx = (cx == h ? cx : (h - 1) / ((h - 1) / cx));
    if(cx == h) break;
    cx = lx + 1;
}