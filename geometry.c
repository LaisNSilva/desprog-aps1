#include <stdio.h>
#include "geometry.h"

#define MIN_DIFF 0.000001

int see_this_case(point p, point a, point b, int* cont){
    int see_case = verify(p, a, b);
    if (see_case == 2){
        return 1;
    } else if (see_case == 1){
        *cont = *cont + 1;
    }
    return 0;
}

int see_final_count(int value){
    if (value % 2 == 0) return 0;
    return 1;
}

double absolute(double a, double b){
    if (a > b){
        return (double) a-b;
    }
    return (double) b-a;
}

int verify(point p, point a, point b) {
    int x_max = a.x, x_min = b.x;
    int y_max = a.y, y_min = b.y;

    if(a.x < b.x){
        x_max = b.x;
        x_min = a.x;
    }

    if(a.y < b.y){
        y_max = b.y;
        y_min = a.y;
    }

    if ((p.x == a.x && p.y == a.y) || (p.x == b.x && p.y == b.y)) return 2;

    if (a.x == b.x){
        if (p.x == a.x){
            if (p.y > y_min && p.y < y_max) return 2;
            return 0;            
        }
        else{
            if(p.x < a.x){
                if (p.y > y_min && p.y <= y_max) return 1;
            }
            return 0;            
        }
    }

    else if (a.y == b.y){
        if (p.y == a.y){
            if (p.x >= x_min && p.x<=x_max){
                return 2;
            }
        }
        return 0;
    }

    else {
        double m = (double) (a.y-b.y)/(a.x - b.x);
        double eq_reta = (double) m*(p.x - a.x) + a.y;
        double y_point_double = (double) p.y;
        double check_diff = absolute(y_point_double, eq_reta);
        if (check_diff < MIN_DIFF){
            if (p.y > y_min && p.y < y_max) return 2;
            return 0; 
        }
        else {
            if (p.y > y_min && p.y <= y_max){
                if(p.x <= x_min){
                    return 1;
                } else {
                    double x_ponto = (double) p.x;
                    if(p.x < x_max){
                        for(double i = x_ponto; i <= x_max; i += MIN_DIFF){
                            double value_y = (double) m*(i - a.x)+a.y;
                            double check_diff_2 = absolute(y_point_double, value_y);
                            if (check_diff_2 < MIN_DIFF) return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int inside(point p, point poly[], int n) {
    int count = 0;
    for(int i = 0; i < n-1; i++){
        int check = see_this_case(p, poly[i], poly[i+1], &count);
        if (check == 1) return check;
    }

    int check_last_case = see_this_case(p, poly[n-1], poly[0], &count);
    if (check_last_case == 1) return check_last_case;

    return see_final_count(count);
}
