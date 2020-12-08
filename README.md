# Introdução a Computação Gráfica

## 1. OpenGL Moderno
  No ínicio desta disciplina, foi proposta um trabalho com os objetivos de verificar se o ambiente de desenvolvimento do OpenGL 3.3 está corretamente configurado e nos familiarizar com a estrutura de um programa OpenGL.
  ## 1.1 Resultados Obtidos
   O código disponibilizado pelo professor foi compilado, nenhum erro foi detectado, apenas alguns warnings foram imprimidos na tela, contudo isso já havia sido informado que iria acontecer. Após a compilação, quando executamos foi imprimido na tela a seguinte imagem:
    
   ![OpenGL](https://github.com/LucasJurani/Computacao_Grafica/blob/main/IMAGENS%20ICG/atividade1.PNG)


## 2. Rasterização
  Foi proposta uma atividade que tinha como objetivo a familiarização dos alunos com os algoritmos de rasterização utilizados em Computação Gráfica, além de trabalhar com o OpenGL. Dessa forma, foram propostas 3 funções, a primeira função chamada PutPixel(), que desenha um pixel na posição escolhida, a função DrawLine(), que rasteriza uma linha, e, por fim, DrawTriangle, que forma um triângulo a partir da rasterização de 3 retas.
  
  
  ## 2.1 PutPixel
  A primeira função desenvolvida, rasterização de um ponto, recebe como parâmetros as coordenadas x,y e cor. Em que foram feitos dois STRUCT's, um para definir as coordenadas x e y dos pontos, e o outro Struct para receber os parâmetros RGBA de cor do pixel.
  Na figura abaixo podemos ver o resultado, vários pontos com cores diferentes.
  
  ![PutPixel](https://github.com/LucasJurani/Computacao_Grafica/blob/main/2.%20Rasteriza%C3%A7%C3%A3o/IMG/opengl1putpixel.PNG)


  ## 2.2 DrawLine
  Esta função rasteriza uma linha na tela utilizando o Algoritmo do Ponto Médio. Em que, a função recebe como parâmetros as coordenadas de seu vértices, inicial e final, e também recebe dois parâmetros RGBA para definir as cores de ambos os pontos. Dessa forma a estrutura da função fica DrawLine(pontoA, PontoB, RGBA, RGBA).
  Outra coisa proposta para a Rasterização das linhas foi a utilização da Interpolação Linear nas cores que compõe as retas.
  Na figura abaixo vemos 4 com interpolação linear.
  
  ![RetasInterpola](https://github.com/LucasJurani/Computacao_Grafica/blob/main/2.%20Rasteriza%C3%A7%C3%A3o/IMG/retas%20com%20interp.PNG)
  
  ## 2.3 DrawTriangle
   Para a função que rasteriza triângulos, pegamos a função DrawLine, e traçamos 3 retas ligandos cada ponto, isto é, uma reta A->B, outra B->C e outra C->A. Dessa forma foi feita a função DrawTriangle, utilizando 3 chamadas da função DrawLine.
    Na figura abaixo podemos ver um triângulo gerado por esta função.
    
   ![Triangulo](https://github.com/LucasJurani/Computacao_Grafica/blob/main/2.%20Rasteriza%C3%A7%C3%A3o/IMG/triangulo.PNG)
    
  ## 2.4 Discussão de Resultados e Dificuldades
  A função PutPixel, de fato foi bem simples de ser feita, contudo a função DrawLine não foi tão fácil. Primeiramente foi feito o código somente para o primeiro octante, e já integrando-o com a Interpolação Linear. Contudo, quando foi feita a expansão para os outros octantes foi encontrada uma certa dificuldade para a implementação de fato. A dificuldade foi superada com um material disponibilizado pela UNIVASF, do professor Jorge Cavalcanti. Resolvidos os problemas na função DrawLine, a função DrawTriangle foi feita, e foi relativamente rápido de ser feito, visto que ela é feita de chamadas do DrawLine.
  
  ## 2.5 Referências

http://letslearnbits.blogspot.com/2014/10/icgt1-interpolacao-de-cores.html
http://www.univasf.edu.br/~jorge.cavalcanti/comput_graf04_prim_graficas2.pdf


## 3. Pipeline Gráfico
  O Objetivo desta parte da disciplina, é buscar a familiaridade com o Pipeline Gráfico através da implementação das transformadas geométricas que o compõem. As bibliotecas GLM e GLEW foram utilizadas para auxiliar esse projeto, o qual consistiu em fazer alterações em alguns trechos de código disponibilizados a fim de visualizar o que cada mudança nas matrizes Model, View e Projection faria com a nossa cena. Primeiramente compilamos o código disponibilizado pelo professor, obtendo a seguinte cena:
  
  ![Imagem1](https://github.com/LucasJurani/Computacao_Grafica/blob/main/IMAGENS%20ICG/Imagem1.PNG)
  
  ## 3.1 Escala
  Nesta parte, trabalhamos com a Matriz Model de forma que com a mudança de alguns parâmetros esperavamos obter uma cena com escala diferente da cena original. Os fatores de escala utilizados foram (x, y, z) = (1/3,3/2,1). Aplicando esses fatores obtemos o seguinte código com a seguinte cena.
  
  ![Codigo1](https://github.com/LucasJurani/Computacao_Grafica/blob/main/IMAGENS%20ICG/code1.PNG)
  ![Cena1](https://github.com/LucasJurani/Computacao_Grafica/blob/main/IMAGENS%20ICG/compiled1.PNG)
  
  ## 3.2. Translação
  Modificamos novamente a Matriz Model, mas agora movemos os objetos da cena de forma que eles ficassem mais para o lado direito da cena. Com o fator de Translação (x, y, z) = (1,0,0), obtemos o seguinte resultado.
  
  ![Codigo2](https://github.com/LucasJurani/Computacao_Grafica/blob/main/IMAGENS%20ICG/code2.PNG)
  ![Cena2](https://github.com/LucasJurani/Computacao_Grafica/blob/main/IMAGENS%20ICG/compiled2.PNG)
  
  ## 3.3 Projeção Perspectiva
  Modificamos a Matriz Projection de forma que o triângulo vermelho fique a frente do triângulo azul. Utilizando a distância d (distância do centro de projeção até a origem do sistema de coordenadas da câmera) igual a 1/8, obtivemos o seguinte resultado.
  
  ![Codigo3](https://github.com/LucasJurani/Computacao_Grafica/blob/main/IMAGENS%20ICG/code3.PNG)
  ![Cena3](https://github.com/LucasJurani/Computacao_Grafica/blob/main/IMAGENS%20ICG/compiled3.PNG)
  
  ## 3.4 Posição da Câmera
  Neste, mantemos a distorção perspectiva feita na Matriz de Projeção no item anterior, e então, modificamos a Matriz View de forma que os dois triângulos sejam agora vistos mais na diagonal. Para isso foram implementados duas matrizes, a matriz B da base da câmera e então calculamos a sua transposta e a outra matriz T que translada a base da câmera. Após isso, foi implementado a Matriz View com o produtos das matrizes bT e T e então aplicamos a transformação da MViews sobre os vértices dos triângulos. Com os vetores Posição da Câmera = (−1/10,1/10,1/10),  Vetor Up da Câmera = (0,1,0),  Ponto para o qual câamera está apontando = (0,0,−1), obtivemos o seguinte resultado:
  
  ![Codigo4](https://github.com/LucasJurani/Computacao_Grafica/blob/main/IMAGENS%20ICG/code4.PNG)
  ![Cena4](https://github.com/LucasJurani/Computacao_Grafica/blob/main/IMAGENS%20ICG/compiled4.PNG)
  
  ## 3.5 Transformações Livres
  Neste, foi proposto que os alunos fizessem modificações nas 3 matrizes trabalhadas, Model, View e Projection, de forma a gerar uma cena diferente das geradas anteriormente. Dessa forma, alterando as 3 matrizes obtemos o seguinte resultado.
  
  ![Cena4](https://github.com/LucasJurani/Computacao_Grafica/blob/main/IMAGENS%20ICG/compiled5.PNG)
  
  ## 3.6 Discussões de Resultados e Dificuldades
  As transformações gráficas feitas em geral não foram dificeis, contudo, vale destacar que o tópico 3.4 Posição da Câmera foi mais complexo, pois nos outros tópicos trabalhamos mais com a modificação de parâmetros, já nesse tópico tivemos que aplicar outros conhecimentos, não foi um desafio grande, mas foi muito interessante. Fora isso, tive certa dificuldade no começo desse projeto, pois quando tentava compilar o código inicial retornava o erro 'GLSL 3.30 is not supported. Supported versions are: 1.10, 1.20, 1.30, 1.00 ES and 3.00 ES, esse problema foi resolvido executando o seguinte comando dentro da pasta do código '$ export MESA_GL_VERSION_OVERRIDE=3.3'.
