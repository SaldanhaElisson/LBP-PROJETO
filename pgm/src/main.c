#include "lastdance.h"


int main(int argc, char *argv[]){

	struct pgm img;
    struct pgm *filterImg;
    unsigned  char *hist;

    filterImg = malloc(sizeof(struct pgm));

	if (argc!=3){
		printf("Formato: \n\t %s <imagemEntrada.pgm> <imagemSaida.pgm>\n",argv[0]);
		exit(1);
	}

	readPGMImage(&img,argv[1]);
	// writePGMImage(&img, argv[2]);
	// viewPGMImage(&img);

    filtrolbp(&img, filterImg);

    hist = malloc(filterImg->c * filterImg->r * sizeof(char));

    histogram(filterImg->pData, filterImg->r, filterImg->c, hist);

    printf("%c", *(hist));

	return 0;

}