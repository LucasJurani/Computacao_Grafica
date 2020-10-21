# Introdução a Computação Gráfica

## 1. Rasterização
  Foi proposta uma atividade que tinha como objetivo a familiarização dos alunos com os algoritmos de rasterização utilizados em Computação Gráfica, além de trabalhar com o OpenGL. Dessa forma, foram propostas 3 funções, a primeira função chamada PutPixel(), que desenha um pixel na posição escolhida, a função DrawLine(), que rasteriza uma linha, e, por fim, DrawTriangle, que forma um triângulo a partir da rasterização de 3 retas.
  
  
## 1.1 PutPixel
  A primeira função desenvolvida, rasterização de um ponto, recebe como parâmetros as coordenadas x,y e cor. Em que foram feitos dois STRUCT's, um para definir as coordenadas x e y dos pontos, e o outro Struct para receber os parâmetros RGBA de cor do pixel.
  Na figura abaixo podemos ver o resultado, vários pontos com cores diferentes.
  
  ![PutPixel](https://github.com/LucasJurani/Computacao_Grafica/blob/main/1.%20Rasteriza%C3%A7%C3%A3o/IMG/opengl1putpixel.PNG)


## 1.2 DrawLine
  Esta função rasteriza uma linha na tela utilizando o Algoritmo do Ponto Médio. Em que, a função recebe como parâmetros as coordenadas de seu vértices, inicial e final, e também recebe dois parâmetros RGBA para definir as cores de ambos os pontos. Dessa forma a estrutura da função fica DrawLine(pontoA, PontoB, RGBA, RGBA).
  Outra coisa proposta para a Rasterização das linhas foi a utilização da Interpolação Linear nas cores que compõe as retas.
  Na figura abaixo vemos 4 com interpolação linear.
  
  ![RetasInterpola](https://github.com/LucasJurani/Computacao_Grafica/blob/main/1.%20Rasteriza%C3%A7%C3%A3o/IMG/retas%20com%20interp.PNG)
  
  ## 1.3 DrawTriangle
   Para a função que rasteriza triângulos, pegamos a função DrawLine, e traçamos 3 retas ligandos cada ponto, isto é, uma reta A->B, outra B->C e outra C->A. Dessa forma foi feita a função DrawTriangle, utilizando 3 chamadas da função DrawLine.
    Na figura abaixo podemos ver um triângulo gerado por esta função.
    ![Triangulo](https://github.com/LucasJurani/Computacao_Grafica/blob/main/1.%20Rasteriza%C3%A7%C3%A3o/IMG/triangulo.PNG)
    
   
