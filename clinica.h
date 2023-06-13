#ifndef CLINICA_H
#define CLINICA_H

void menu();

void imprimirCastracao(int type, char nome[250], char dia[250]);

void imprimirVendaRacao(int pequena, char tamPequena, float precoPequena,
                        int media, char tamMedia, float precoMedia,
                        int grande, char tamGrande, float precoGrande,
                        float *total, int quantidade);

#endif
