# FILTRO LBP 
**Projeto Final da Caderia de Laboratorio da Programção - IFCE - CIÊNCIA DA COMPUTAÇÃO**

**Aluno:** Elisson Monteiro Saldanha

**Aluno:** Mateus 

**Aluno**: Vinicius

## Descrição do Projeto

O LBP (Local Binary Patterns) é um algoritmo que pode ser aplicado para discriminar diferentes texturas em imagens. Este método está baseado na realção de um pixel com seus vizinhos.

A versão que implementamos utiliza uma janela de 3x3 pixels que desliza por toda a imagem e compara o pixel central com seus vizinhos. Se o valor do pixes vizinho for mair ou igual ao do centro, naquela posição será atribuída o valor dee 1, caso contrário, será atribuído o valor 0. A operação é realizada para todos os 8 vizinhos do pixel central em sentido horário, gerando um conjunto de 8 bits, cujo número decimal correspondente será atribuído a uma nova imagem( de mesma dimensão da imagem de entrada) na mesma posição do pixel central.

Após cálcularmos o LBP, computamos um histograma da imagem gerada (imagem LBP). Este procedimento irá resultar em uma vetor de 256 elementops, onde cada posição (índice) do vetor contém a quantidade das ocorrências do pixel de mesmo valor na imagem LBP

Utilizamos a [base de dados Epistroma](http://fimm.webmicroscope.net). Esta base de dados contém um subconjunto para treino/validação copm 656 imagens de microscopia de câncer colorretal com resolução espacial variando de 293 x 294 a 1088 x 1089 pixels. As imagens foram convertidas para nível de cinza de 9 bits em formato pgm. A classe da imagem (ròtulo) está identificada no primeiro caractere do nome do arquivo, sendo 0 para epitheliun e 1 para stroma. 


