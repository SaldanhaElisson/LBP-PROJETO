#ifndef __LBP_H_
#define __LBP_H_

#include "estrutura.h"
#include <dirent.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void filtrolbp(const struct pgm *img, unsigned char *hist);
void readPGMImage(struct pgm *pio, char *filename);
void writePGMImage(struct pgm *pio, char *filename);
void viewPGMImage(struct pgm *pio);
void gravarCSV(unsigned char *hist, char *const fileName, char *nome, int linha);
#endif // __LISTA05_H_