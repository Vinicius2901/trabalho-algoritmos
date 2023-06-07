#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void menu ();
void imprimirVendaRacao(int pequena, char tamPequena, float precoPequena,
                        int media, char tamMedia, float precoMedia,
                        int grande, char tamGrande, float precoGrande,
                        float *total, int quantidade);

void imprimirCastracao(int type, char nome[250], char dia[250]);

int main ()
{
    //Declaração de variáveis.
    char nome [250];//Nome do cliente.
    char data [250];//Data do serviço.
    char pet [250]; //Nome do animal.
    int animal;     //Tipo de animal.
    int servico;    //Entrada do serviço.
    float tot = 0;      //Total a se pagar.
    char ser [250]; //Saída do serviço.
    char *tam;      //Tamanho do pacote.
    float *pre;     //Preço.
    int num;        //Número de ração.
    char med [250]; //Medicamento solicitado.
    char tel [250]; //Número de telefone.
    int i;          //Índice do vetor.
    int pequena = 0, media = 0, grande = 0;
    int locp, locm, locg;

    
    //Inputs.

    //Nome do cliente.
    printf("Qual seu nome: ");
    fgets (nome, 250, stdin);
    setbuf (stdin, 0);


    //Tipo de serviço.
    menu ();
    scanf (" %i", &servico);

    
    //Casos.
    switch (servico)
    {
    case 1://Vacina.
        //Nome do pet.
        setbuf (stdin, 0);
        printf("Qual o nome do seu pet?\n");
        fgets(pet, 250, stdin);
        //Tipo de animal.
        printf("Seu animal eh:\n");
        printf("(1) Felino\n(2) Canino\n");
        scanf(" %i", &animal);
        //Data da consulta.
        printf("Escreva a data da consulta: ");
        setbuf (stdin, 0);
        fgets(data, 250, stdin);
        tot = 190;
        strcpy(ser, "Vacina");
    break;
    case 2://Castração.
        //Nome do pet.
        setbuf (stdin, 0);
        printf ("Qual o nome do seu pet?\n");
        fgets (pet, 250, stdin);
        //Tipo de animal.
        printf ("Seu animal eh:\n");
        printf ("(1) Felino\n(2) Canino\n");
        scanf (" %i", &animal);
        //Data da consulta.
        printf ("Escreva a data da consulta: ");
        setbuf (stdin, 0);
        fgets (data, 250, stdin);
        if (animal == 1)
        {
            tot = 220;
        }
        else
        {
            tot = 280;
        }
        strcpy (ser, "Castracao");
        break;
    case 3://Venda de ração.
        //Pegar o numero de pacotes.
        printf ("Numero de pacotes:\n");
        scanf (" %i", &num);
        //Tamanho do vetor número de rações.
        pre = malloc(num*sizeof(int));
        tam = malloc(num*sizeof(char));
        //Preço da ração pequena/média/grande sendo armazenados em um vetor.
        for (i = 0; i < num; i++)
        {
            printf ("\nTamanho do pacote desejado (%i):\n\n(P) Pequeno \n(M) Medio \n(G) Grande\n\n", i+1);
            scanf (" %c", &tam[i]);
            tam[i] = toupper (tam[i]);
            if (tam[i] == 'P')
            {
                pre[i] = 30;
                pequena++;
                locp = i;
            }
            else if (tam[i] == 'M')
            {
                pre[i] = 70;
                media++;
                locm = i;
            }
            else if (tam[i] == 'G')
            {
                pre[i] = 120;
                grande++;
                locg = i;
            }
        tot += pre[i];
        }
        strcpy (ser, "Venda de racoes");
        break;
    case 4://Medicamento.
        strcpy (ser, "Encomenda de medicamento");
        printf ("Medicamento: \n");
        setbuf (stdin, 0);
        fgets (med, 250, stdin);
        printf ("Numero de celular: ");
        setbuf (stdin, 0);
        fgets (tel, 250, stdin);
        break;
    default:
        break;
    }
    printf ("\n\nCliente: %s", nome);
    printf ("Servico: %s\n", ser);
    switch (servico)
    {
    case 1 ... 2:
        imprimirCastracao(animal, pet, data);
        break;
    case 3:
        imprimirVendaRacao(pequena, tam[locp], pre[locp],
                       media, tam[locm], pre[locm],
                       grande, tam[locg], pre[locg],
                       &tot, num);
        break;
    case 4:
        printf ("%s", med);
        printf ("Contato: %s\n", tel);
        break;

    default:
        break;
    }
    if (tot > 0)
    {
        printf ("Total: R$%.2f\n", tot);
    }
    return 0;
}

void menu ()
{
    printf ("\nServicos disponiveis: \n");
    printf ("\n(1) Vacina\n");
    printf ("(2) Castracao\n");
    printf ("(3) Venda de racao\n");
    printf ("(4) Medicamentos\n");
    printf ("\nDigite uma das opcoes: ");
}

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
