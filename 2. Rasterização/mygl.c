#include "mygl.h"
#include <stdio.h>

unsigned char* fb_ptr = NULL;

void InitMyGl(void) {
    fb_ptr = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 4 * sizeof(char));	

    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; ++i) {
        fb_ptr[i * 4] = 0;
        fb_ptr[i * 4 + 1] = 0;
        fb_ptr[i * 4 + 2] = 0;
        fb_ptr[i * 4 + 3] = 255;
    }    
}

unsigned char* GetFBMemPtr(void) {
	return fb_ptr;
}

void CloseMyGl(void) {
    if (!fb_ptr)
        free(fb_ptr);
}

//
// Calcula a distância euclidiana entre dois pontos
float distancia(pixel a, pixel b){
    return sqrt(pow(b.x-a.x, 2) + pow(b.y-a.y, 2));
}

void PutPixel(pixel pixel, rgba cores){

    int posicao = pixel.x*4 + pixel.y*4*IMAGE_WIDTH;

    fb_ptr[posicao] = cores.r;
    fb_ptr[posicao++] = cores.g;
    fb_ptr[posicao++] = cores.b;
    fb_ptr[posicao++] = cores.a;
    
}

// p = distanciaParcial/distanciaTotal;
rgba interpolar(float p, rgba cor1, rgba cor2){
	rgba cor;
	cor.r = cor1.r*p + (1-p)*cor2.r;
	cor.g = cor1.g*p + (1-p)*cor2.g;
	cor.b = cor1.b*p + (1-p)*cor2.b;
	cor.a = cor1.a*p + (1-p)*cor2.a;

	return cor;
}

void DrawLine(pixel pixel1, pixel pixel2, rgba cor1, rgba cor2){
    //printf("debug\n");
            
    int dx = pixel2.x - pixel1.x;
    int dy = pixel2.y - pixel1.y;

    pixel ppixel1 = pixel1;
    pixel ppixel2 = pixel2; 

    int D;
    //int D = 2 * (dy-dx);
    //float inc_L = 2*dy;
    //float inc_NE = 2 * (dy-dx);

    float distanciaTotal = distancia(ppixel1, ppixel2);
    float distanciaParcial;
    float distanciaRestante;

    rgba cor = cor1;
    //printf("debug12\n");

    if (dx<0)
    {
        /* code */

        DrawLine(ppixel2, ppixel1, cor2, cor1);
        return;
    }

    int inclinacao;

    if(dy<0)
        inclinacao = -1;
    else
        inclinacao = 1;

    PutPixel(ppixel1, cor1);

    
    //printf("debug\n");

    if(dx >= inclinacao*dy){
        if(dy < 0){
            D = 2 * (dx+dy);
            while (ppixel1.x < ppixel2.x){
                if(D < 0){
                    D += 2*(dy+dx);
                    ppixel1.x++;
                    ppixel1.y--;    
                    //printf("%d %d\n", ppixel1.x, ppixel1.y);
                }else{
                    D += 2*dy;
                    ppixel1.x++;
                    //printf("%d %d\n", ppixel1.x, ppixel1.y);
                }
                
                distanciaParcial = distancia(ppixel1, ppixel2);
                distanciaRestante = (distanciaParcial/distanciaTotal);
                cor = interpolar(distanciaRestante, cor1, cor2);
                PutPixel(ppixel1, cor);
            }

        }else{

            D = 2* (dy-dx);
            while(ppixel1.x < ppixel2.x){
                if (D<0)
                {
                    D+=2*dy;
                    ppixel1.x++;
                }else{
                    D += 2* (dy-dx);
                    ppixel1.x++;
                    ppixel1.y++;
                }
                distanciaParcial = distancia(ppixel1, ppixel2);
                distanciaRestante = (distanciaParcial/distanciaTotal);
                cor = interpolar(distanciaRestante, cor1, cor2);
                PutPixel(ppixel1, cor);

            }
        }
    }else{//m>1
        if(dy<0){
            D = dy + 2*dx;
            while(ppixel1.y > ppixel2.y){
                if(D < 0){
                    D += 2* (dy+dx);
                    ppixel1.x++;
                    ppixel1.y--;
                }
                distanciaParcial = distancia(ppixel1, ppixel2);
                distanciaRestante = (distanciaParcial/distanciaTotal);
                cor = interpolar(distanciaRestante, cor1, cor2);
                PutPixel(ppixel1, cor);
            
            }
        }else{
            D = dy - 2*dx;
            while(ppixel1.y < ppixel2.y){
                if (D<0)
                {
                    /* code */
                    D += 2* (dy-dx);
                    ppixel1.x++;
                    ppixel1.y++;
                }else{
                    D += -2*dx;
                    ppixel1.y++;
                }
                distanciaParcial = distancia(ppixel1, ppixel2);
                distanciaRestante = (distanciaParcial/distanciaTotal);
                cor = interpolar(distanciaRestante, cor1, cor2);
                PutPixel(ppixel1, cor);
            }
        }
    }
    PutPixel(ppixel2, cor2);
    
     
}


void DrawTriangle(pixel pixel1, pixel pixel2, pixel pixel3, rgba cor1, rgba cor2, rgba cor3){
    DrawLine(pixel1, pixel2, cor1, cor2);
    DrawLine(pixel2, pixel3, cor2, cor3);
    DrawLine(pixel3, pixel1, cor3, cor1);
}


// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    pixel p1 = {40, 120};
    rgba c1 = {255,   0,   0, 255};		
    pixel p2 = {255, 255};
    rgba c2 = {0,   255,   0, 255};		
    pixel p3 = {29, 256}; 
    rgba c3 = {0,   0,   255, 255};		
    pixel p4 = {150, 150};
    rgba c4 = {255,   255,   255, 255};	
    pixel p5 = {200, 10};
    rgba c5 = {50,   100,   200, 255};
    pixel p6 = {100, 200};
    rgba c6 = {95,   40,   150, 255};
    pixel p7 = {0, 0};
    pixel p8 = {510,510};
    pixel p10 = {0, 256};
    rgba c10 = {255,   200,   10, 255};

    
    // DrawLine(p1, p2, c1, c2);
    // DrawLine(p7, p8, c3, c4);
    // DrawLine(p5, p6, cor5, c3);
    // DrawLine(p10, p4, c10, c1);

    DrawTriangle(p1,p2,p5,c1,c2,c3);
    //DrawTriangle(p3,p4,p5,c4,c5,c6);

    PutPixel(p1, c1);
    PutPixel(p2, c2);
    PutPixel(p3, c3);
    //PutPixel(p4, c4);
    //PutPixel(p5, c5);
    //PutPixel(p6, c6);
    
}