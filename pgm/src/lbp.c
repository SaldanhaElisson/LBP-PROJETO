#include "header.h"

void filtrolbp(const struct pgm *img, struct pgm *fil) {
  // Filtro LBP. Janela de 8 bits. Método Comparativo
  // Prenchimento da estrutura
  fil->tipo = 5;
  fil->r = img->r;
  fil->c = img->c;
  fil->mv = 256;
  fil->pData = (unsigned char *)calloc(fil->r * fil->c, sizeof(unsigned char));

  // Execução do filtro LBP
  int l = fil->r, c = fil->c;  // linhas e colunas
  unsigned char soma, bjanela; // soma dos bits das janelas e bit da janela
  int j, k, sent, pos; // j = posição linha, k = posição coluna, sent = sentido
                       // de rotação, pos = posição do bit na janela

  for (int i = 0; i < l * c; i++) { // i = posição ponteiro inicial
    soma = 0, j = -1, k = -1, sent = 1, pos = 0;
    do {
      bjanela = 0; // Valor da janela de filtro, 0 para fora da matriz

      if (i < c && j == -1) {                 // superior
      } else if (!(i % c) && k == -1) {       // esquerdo
      } else if (i > (l * c) - c && j == 1) { // inferior
      } else if (!((i + 1) % c) && k == 1) {  // direito
      } else {
        bjanela = *(img->pData + i + k + j * c); // parte interna
      }
      if (bjanela >= *(img->pData + i)) { // metodo comparativo
        soma += pow(2, pos);
      }
      pos++;

      switch (sent) { // J e K desloca a janela, sent Muda o Sentido da janela
      case 1:
        k++;
        if (k == 1)
          sent++;
        break;
      case 2:
        j++;
        if (j == 1)
          sent++;
        break;
      case 3:
        k--;
        if (k == -1)
          sent++;
        break;
      case 4:
        j--;
        if (j == -1)
          sent++;
        break;
      }
    } while (sent <= 4);
    *(fil->pData + i) = soma; // Recebe a soma dos bits no ponteiro de saída
  }
}

void histogram(const struct pgm *img, unsigned char *hist) {
  //hist = calloc(img->mv, sizeof(unsigned char));
  for (int i = 0; i < img->r * img->c; i++) {
    *(hist + *(img->pData + i)) += 1;
  }
}

void gravarCSV(unsigned char *hist, char *const fileName, char *nome,
               int linha) {
  FILE *arquivoCVS;

  if (linha == 0) { // Cria ou limpa o arquivo para escrita do CSV
    arquivoCVS = fopen(nome, "w");
    if (arquivoCVS == NULL) {
      printf("Erro na abertura do arquivo.\n\n");
      exit(1);
    }

    fclose(arquivoCVS);
  }

  // Escrevendo no fim do arquivo
  arquivoCVS = fopen(nome, "a+b");
  for (int i = 0; i < 256; i++) {
    fprintf(arquivoCVS, "%d,", *(hist + i));
  }

  fprintf(arquivoCVS, "%c\n", fileName[0]);

  fclose(arquivoCVS);
}