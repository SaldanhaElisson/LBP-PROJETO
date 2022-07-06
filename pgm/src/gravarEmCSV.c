#include <stdio.h>
#include <stdlib.h>

void gravarEmCSV(const unsigned char *const hist, const int r, const int c, char *const type){
    FILE *arquivoCVS;

    // adcionar um arquivo no fim de curso
    arquivoCVS = fopen("teste2.csv", "ab");
    
    for(int i = 0; i < 255; i++){
        // printf("%d, ", *(hist+i));
        fprintf(arquivoCVS, "%d,", *(hist+i));
    }

    fprintf(arquivoCVS, "%c\n", type[23]);

    fclose(arquivoCVS);

}