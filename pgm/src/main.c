#include "lbp.h"

int main(int argc, char *argv[]) {

  struct pgm img;
  unsigned char *hist;
  char *fileNames;
  char *path; // String diretorio
  char *nome; // Nome do arquivo

  //Calculo de tempo
  clock_t begin, end;
	double time_per_img, time_total=0;

  if( (argc) < 3){
    puts("Erro.");
    puts(".Formato: ./buid/main [caminho do diretorio das imagnes] [Nome do arquivo CSV]");
    exit(10);
  }

  path = argv[1];
  nome = argv[2];

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
      hist = calloc(img.mv, sizeof(unsigned char));

      begin = clock();
      filtrolbp(&img, hist);
      end = clock();
      time_per_img = (double)(end - begin) / CLOCKS_PER_SEC;
		  time_total += time_per_img;
      

      gravarCSV(hist, lsdir->d_name, nome, count);
      count++;
    }
  }

  if (count == 0) {
  printf("Nenhum arquivo encontrado\n");
  }

  printf("Tempo médio: %lf\n",time_total/count+1);
	printf("Tempo Total: %lf\n",time_total);

  free(fileNames);
  closedir(dir);

  return 0;
}