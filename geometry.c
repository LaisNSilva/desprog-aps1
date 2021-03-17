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
        x_min = b.x;
    }
    int y_max;
    int y_min;
    if(a.y>= b.y){
        y_max = a.y;
        y_min = b.y;
    }
    else{
        y_max = b.y;
        y_min = b.y;
    }


    
    // se a.x e b.x forem iguais
    if (a.x == b.x){
        // verifica se está na reta
        if (p.x == a.x){
            // verifica se está nos limites do segmento
            if (p.y >= y_min && p.y<=y_max){
                return 2;
            }
            // se não está no limite do segmento o raio disparado não cruza
            else{
                return 0;
            }
        }
        // se não esta no mesmo x
        else{
            // se estiver nos limites de y o raio cruza
            //apenas de p.x estiver a esquerda da linha
            if(p.x < a.x){
                if (p.y >= y_min && p.y<=y_max){
                    return 1;
                }
                // se esta fora dos limites o raio não curza
                else{
                    return 0;
                }
            }
            // se p.x estiver a direita da linha não cruza
            else{
                return 0;
            }
            
        }
    }

    // se a.y e b.y forem iguais
    else if (a.y == b.y){
        // ve esta está na reta
        if (p.y == a.y){
            // ve esta no segmento
            if (p.x >= x_min && p.x<=x_max){
                return 2;
            }
            // se não estiver no segmento o raio cruza toda a aresta
            else{
                return 1;
            }
        }
        // se não tem o mesmo y o raio a direita não cruza essa aresta
        else{
            return 0;
        }
    }



    else{
        // sem divisões por zero
        double m = (a.y-b.y)/(a.x - b.x);
        double eq_reta = m*(p.x - a.x)+a.y;
        double y_ponto = (double)p.y;
        double verifica = y_ponto-eq_reta;
        if (verifica < 0){
            verifica = eq_reta-y_ponto;
            
        }
        
        //printf("y_ponto = %f", y_ponto);
        if (verifica<0.000001){
            
            // está contido da reta, mas não sei ainda se está fora dos limites do segmento
            // se está contido no segmento
            if (p.y >= y_min && p.y<=y_max){
                return 2;
            }
            // se está na reta mas não no segmento, esta para fora
            else{
                return 0;
            }
            
        }

        // não está sobre a reta
        else{
            // vai fazer o raio para a direita
            for(int i = p.x; i<= x_max; i++ ){
                // descobre o y da reta para cada x do raio
                double v = m*(i - a.x)+a.y;
                double verifica2 = y_ponto-v;
                if (verifica2<0){
                    verifica2 = v-y_ponto;
                }
                // verifica se y da reta é igual ao y do ponto (pq o raio a direita so muda x e não o y)
                if (verifica2<0.000001){
                    // verifica de y está nos limites
                    if (p.y >= y_min && p.y<=y_max){
                        return 1;
                    }
                    else{
                        return 0;
                    }
                    
                } 

            }

        }

    }
    
    
    return 0;
}

int inside(point p, point poly[], int n) {
    return 0;
}
