//find quadrant
//works good if points are integer, better than sorting by arg 
auto find_quadrant = [](const Point &p) {
    if(p.x > 0 && p.y >= 0) return 0; //[0, 90)
    else if(p.x <= 0 && p.y > 0) return 1;//[90, 180)
    else if(p.x < 0 && p.y <= 0) return 2;//[180, 270]
    else return 3;//[270, 360)
};

sort(vx.begin(), vx.end(), [&](Point &p1, Point &p2){
    int q1 = find_quadrant(p1), q2 = find_quadrant(p2);
    if(q1 != q2) return q1 < q2;
    else return p1.cross(p2) > 0;
});