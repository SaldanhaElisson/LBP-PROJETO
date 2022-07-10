#include "header.h"

int main() {

  struct pgm img, filterImg;
  unsigned char *hist;
  char *fileNames;
  char *path = "./datasets/oncotex_pgm/"; // String diretorio
  char *nome = "Histograma.csv";          // Nome do arquivo

  if (!strstr(nome, ".csv")) {
    printf("Arquivo não está em formato .csv\n\n");
    exit(1);
  }

  // Estrutura para abrir diretorio no caminho dado
  DIR *dir;
  struct dirent *lsdir;
  dir = opendir(path);
  if (!dir) {
    printf("Diretorio não encontrado\n\n");
    exit(1);
  }

  // Laço para selecionar os arquivos do diretorio
  int tam, count = 0;
  while ((lsdir = readdir(dir)) != NULL) {

    // Aloca espaço para o nome e caminho do arquivo
    tam = strlen(path) + strlen(lsdir->d_name) + 1;
    fileNames = malloc(tam * sizeof(char));
    strcpy(fileNames, path);          // adiciona string caminho
    strcat(fileNames, lsdir->d_name); // concatena string nome do arquivo

    if (strstr(lsdir->d_name, ".pgm")) { // Filtra somente arquivos .pgm

      readPGMImage(&img, fileNames);
      filtrolbp(&img, &filterImg);
      hist = calloc(img.mv, sizeof(unsigned char));
      histogram(&filterImg, hist);
      gravarCSV(hist, lsdir->d_name, nome, count);
      count++;
    }
  }

  free(fileNames);
  closedir(dir);

  return 0;
}