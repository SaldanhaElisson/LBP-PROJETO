void (const unsigned char * hist){
    FILE *arquivoCVS;

    arquivoCSV = fopen("desafio.csv, w");

    fwrite(pio->pData, sizeof(unsigned char),pio->c * pio->r, fp);

    fclose(arquivoCSV);

}