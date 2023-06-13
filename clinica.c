#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "clinica.h"

//Função para mostrar os serviços disponíveis.
void menu ()
{
    printf ("\nServicos disponiveis: \n");
    printf ("\n(1) Vacina\n");
    printf ("(2) Castracao\n");
    printf ("(3) Venda de racao\n");
    printf ("(4) Medicamentos\n");
    printf ("\nDigite uma das opcoes: ");
}

//Função que mostra os dados da Castração/Vacina.
void imprimirCastracao(int type, char nome[250], char dia[250])
{
    if (type == 1)
    {
        printf ("Felino: %s", nome);
    }
    else
    {
        printf ("Canino: %s", nome);
    }
    printf ("Data: %s", dia);
}

//Função que mostra a venda de rações.
void imprimirVendaRacao(int pequena, char tamPequena, float precoPequena,
                        int media, char tamMedia, float precoMedia,
                        int grande, char tamGrande, float precoGrande,
                        float *total, int quantidade)
{
    if (pequena > 0)
    {
        printf("%i unidade(s) de tamanho %c ... %.2f\n", pequena, tamPequena, precoPequena);
    }
    if (media > 0)
    {
        printf("%i unidade(s) de tamanho %c ... %.2f\n", media, tamMedia, precoMedia);
    }
    if (grande > 0)
    {
        printf("%i unidade(s) de tamanho %c ... %.2f\n", grande, tamGrande, precoGrande);
    }
    printf("%.2f\n", *total);
    if (quantidade > 1)
    {
        *total = *total * 9 / 10;
        printf("Desconto: 10%%\n");
    }
    else
    {
        printf("Desconto: 0%%\n");
    }
}