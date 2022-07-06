#include "lastdance.h"
#include <math.h>

#include <dirent.h>
#include <string.h>

#define TAMCHAR 256

int main(int argc, char *argv[]){

	struct pgm img;
    struct pgm *filterImg;
    unsigned  char *hist;
	char teste[1000][100];

    filterImg = malloc(sizeof(struct pgm));

	// if (argc!=3){
	// 	printf("Formato: \n\t %s <imagemEntrada.pgm> <imagemSaida.pgm>\n",argv[0]);
	// 	exit(1);
	// }

	DIR *dir;
    struct dirent *lsdir;

    dir = opendir("./datasets/oncotex_pgm");

	int count = 0;
    /* print all the files and directories within directory */
	puts("aqui");
    while ( ( lsdir = readdir(dir) ) != NULL )
    {
		strcpy(teste[count],"./datasets/oncotex_pgm/");
		strcat(teste[count], lsdir->d_name);
		count++;
					
    }

	for(int i = 2; i < count; i++){
			// printf("%s \n", teste[i]);
			readPGMImage(&img, teste[i]);
			filtrolbp(&img, filterImg);
			hist = malloc(TAMCHAR * sizeof(unsigned int));
			histogram(filterImg->pData, filterImg->r, filterImg->c, hist);
			gravarEmCSV(hist, filterImg->r, filterImg->c, teste[i]);
	}

	for(int i = 0; i < 200; i++){
		filter->(pData+i);
	}

	

    closedir(dir);

	// writePGMImage(&img, argv[2]);
	// viewPGMImage(&img);




	// // lendo histograma
	//  for (int i = 0; i < 255; i++) {
    // 	printf("%d, ", *(hist+i));
  	// }


	return 0;

}