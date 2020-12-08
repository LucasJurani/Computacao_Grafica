#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "core.h"
//#include "frame_buffer.h"


void InitMyGl(void); // Inicializa o frame buffer 
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a memória do framebuffer

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);



//
typedef struct color_rgba
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} rgba;

typedef struct pixel
{
    int x;
    int y;
} pixel;

float distancia(pixel a, pixel b);

//Em que a variável P = distanciaParcial / distanciaTotal;
rgba interpolar(float p, rgba cor1, rgba cor2);

void PutPixel(pixel, rgba);
void DrawLine(pixel, pixel, rgba, rgba);
void DrawTriangle(pixel, pixel, pixel, rgba, rgba, rgba);
//

#endif  // MYGL_H
