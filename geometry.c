#include <math.h>
#include <stdio.h>

#include "geometry.h"


int verify(point p, point a, point b) {
    int x_max;
    int x_min;
    if(a.x>= b.x){
        x_max = a.x;
        x_min = b.x;
    }
    else{
        x_max = b.x;
        x_min = a.x;
    }
    int y_max;
    int y_min;
    if(a.y>= b.y){
        y_max = a.y;
        y_min = b.y;
    }
    else{
        y_max = b.y;
        y_min = a.y;
    }

    if (p.x == a.x && p.y == a.y){
        return 2;
    }
    if (p.x == b.x && p.y == b.y){
        return 2;
    }

    if (a.x == b.x){
        if (p.x == a.x){
            if (p.y > y_min && p.y < y_max){
                return 2;
            }
            else{
                return 0;
            }
        }
        else{
            if(p.x < a.x){
                if (p.y > y_min && p.y <= y_max){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
            
        }
    }

    else if (a.y == b.y){
        if (p.y == a.y){
            if (p.x >= x_min && p.x<=x_max){
                return 2;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }

    else{
        double m = (double)(a.y-b.y)/ (double)(a.x - b.x);
        double eq_reta = (double) m*(p.x - a.x)+a.y;
        double y_ponto = (double)p.y;
        double verifica = y_ponto-eq_reta;
        if (verifica < 0){
            verifica = eq_reta-y_ponto;
        }
        if (verifica < 0.000001){
            if (p.y > y_min && p.y < y_max){
                return 2;
            }
            else{
                return 0;
            }
            
        }
        else {
            if (p.y > y_min && p.y <= y_max){
                if(p.x <= x_min){
                    return 1;
                } else {
                    double x_ponto = (double) p.x;
                    if(p.x < x_max){
                        for(double i = x_ponto; i <= x_max; i += 0.000001){
                            double v = (double) m*(i - a.x)+a.y;
                            double verifica2 = (double) y_ponto-v;
                            if (verifica2 < 0){
                                verifica2 = (double) v-y_ponto;
                            }
                            if (verifica2 < 0.000001){
                                return 1;
                            }
                        }
                    } else {
                        return 0;
                    }
                }
            } else {
                return 0;
            }
        }
    }
    return 0;
}

int inside(point p, point poly[], int n) {
    
    int contador=0;
    for(int i=0; i<(n-1); i++){
        int ver = verify(p, poly[i], poly[i+1]);
        if (ver ==2){
            return 1;
        }
        if (ver == 1){
            contador++;
        }

    }
    // verificando a ultima aresta
    int ultima = verify(p, poly[n-1], poly[0]);
    if (ultima ==2){
        return 1;
    }
    if (ultima==1){
        contador++;
    }
    printf("contador %d\n", contador);

    if(contador%2==0){
        return 0;
    }
    else{
        return 1;
    }



    
}
