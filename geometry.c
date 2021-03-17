#include <math.h>

#include "geometry.h"


int verify(point p, point a, point b) {
    double m = (a.y-b.y)/(a.x - b.x);
    double eq_reta = m*(p.x - a.x)+a.y;
    double y_ponto = (double)p.y;
    if (abs(y_ponto-eq_reta)<0.000001){
        return 2;
    }

    else{
        int x_max;
        if(a.x >= b.x){
            x_max = a.x;
        }
        else{
            x_max = b.x;
        }
        for(int i = p.x; i<= x_max; i++ ){
            double v = m*(i - a.x)+a.y;
           if (abs(y_ponto-v)<0.000001){
                return 1;
            } 

        }

    }

    
    return 0;
}

int inside(point p, point poly[], int n) {
    return 0;
}
