#include <stdio.h>
#include <stdlib.h>

void gravarEmCSV(const unsigned char *const hist, const int r, const int c, char *const type){
    FILE *arquivoCVS;

    // adcionar um arquivo no fim de curso
    arquivoCVS = fopen("desafio.csv", "w+b");
    

    for(int i = 0; i < 255; i++){
        // printf("%d, ", *(hist+i));
        fprintf(arquivoCVS, "%d,", *(hist+i));
    }

    // verificando se está pegando o numero 
    printf("aqui %c", type[6]);

    fprintf(arquivoCVS, "aqui %c", type[6]);

    fclose(arquivoCVS);

}