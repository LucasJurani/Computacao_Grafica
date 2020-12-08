# Introdução a Computação Gráfica

## 1. OpenGL Moderno
  No ínicio desta disciplina, foi proposta um trabalho com os objetivos de verificar se o ambiente de desenvolvimento do OpenGL 3.3 está corretamente configurado e nos familiarizar com a estrutura de um programa OpenGL.


## 2. Rasterização
  Foi proposta uma atividade que tinha como objetivo a familiarização dos alunos com os algoritmos de rasterização utilizados em Computação Gráfica, além de trabalhar com o OpenGL. Dessa forma, foram propostas 3 funções, a primeira função chamada PutPixel(), que desenha um pixel na posição escolhida, a função DrawLine(), que rasteriza uma linha, e, por fim, DrawTriangle, que forma um triângulo a partir da rasterização de 3 retas.
  
  
# 2.1 PutPixel
  A primeira função desenvolvida, rasterização de um ponto, recebe como parâmetros as coordenadas x,y e cor. Em que foram feitos dois STRUCT's, um para definir as coordenadas x e y dos pontos, e o outro Struct para receber os parâmetros RGBA de cor do pixel.
  Na figura abaixo podemos ver o resultado, vários pontos com cores diferentes.
  
  ![PutPixel](https://github.com/LucasJurani/Computacao_Grafica/blob/main/2.%20Rasteriza%C3%A7%C3%A3o/IMG/opengl1putpixel.PNG)


 # 2.2 DrawLine
  Esta função rasteriza uma linha na tela utilizando o Algoritmo do Ponto Médio. Em que, a função recebe como parâmetros as coordenadas de seu vértices, inicial e final, e também recebe dois parâmetros RGBA para definir as cores de ambos os pontos. Dessa forma a estrutura da função fica DrawLine(pontoA, PontoB, RGBA, RGBA).
  Outra coisa proposta para a Rasterização das linhas foi a utilização da Interpolação Linear nas cores que compõe as retas.
  Na figura abaixo vemos 4 com interpolação linear.
  
  ![RetasInterpola](https://github.com/LucasJurani/Computacao_Grafica/blob/main/2.%20Rasteriza%C3%A7%C3%A3o/IMG/retas%20com%20interp.PNG)
  
  # 2.3 DrawTriangle
   Para a função que rasteriza triângulos, pegamos a função DrawLine, e traçamos 3 retas ligandos cada ponto, isto é, uma reta A->B, outra B->C e outra C->A. Dessa forma foi feita a função DrawTriangle, utilizando 3 chamadas da função DrawLine.
    Na figura abaixo podemos ver um triângulo gerado por esta função.
    
   ![Triangulo](https://github.com/LucasJurani/Computacao_Grafica/blob/main/2.%20Rasteriza%C3%A7%C3%A3o/IMG/triangulo.PNG)
    
  # 2.4 Discussão de Resultados e Dificuldades
  A função PutPixel, de fato foi bem simples de ser feita, contudo a função DrawLine não foi tão fácil. Primeiramente foi feito o código somente para o primeiro octante, e já integrando-o com a Interpolação Linear. Contudo, quando foi feita a expansão para os outros octantes foi encontrada uma certa dificuldade para a implementação de fato. A dificuldade foi superada com um material disponibilizado pela UNIVASF, do professor Jorge Cavalcanti. Resolvidos os problemas na função DrawLine, a função DrawTriangle foi feita, e foi relativamente rápido de ser feito, visto que ela é feita de chamadas do DrawLine.
  
  # 2.5 Referências

http://letslearnbits.blogspot.com/2014/10/icgt1-interpolacao-de-cores.html
http://www.univasf.edu.br/~jorge.cavalcanti/comput_graf04_prim_graficas2.pdf
