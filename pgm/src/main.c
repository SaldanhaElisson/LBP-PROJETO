#include "lastdance.h"


#define TAMCHAR 256
#define MAXFILESNAMES 1000
#define MAXCHARNAME 100

int main(int argc, char *argv[]){

	struct pgm img; // arquivo original
    struct pgm *filterImg; // arquivoDepoisDeFIltrado
    unsigned  char *hist; // histograma 
	char fileNames[MAXFILESNAMES][MAXCHARNAME]; // guargar os nomes de arquivos diretorios


    filterImg = malloc(sizeof(struct pgm));

	
	DIR *dir;
    struct dirent *lsdir;

    dir = opendir("./datasets/oncotex_pgm");

	int count = 0;
    /* print all the files and directories within directory */
    while ( ( lsdir = readdir(dir) ) != NULL )
    {
		strcpy(fileNames[count],"./datasets/oncotex_pgm/");
		strcat(fileNames[count], lsdir->d_name);
		count++;
					
    }


	for(int i = 2; i < count; i++){
			// printf("%s \n", teste[i]);
			readPGMImage(&img, fileNames[i]); // pegar os dados da imagem e passar para estrutura pmg declarada como img
			filtrolbp(&img, filterImg);  
			hist = calloc(TAMCHAR, sizeof(unsigned int));
			histogram(filterImg->pData, filterImg->r, filterImg->c, hist);
			gravarEmCSV(hist, fileNames[i]);
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