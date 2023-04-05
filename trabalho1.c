#include <stdio.h>
#include<string.h>

int main ()
{
    char nome [250];
    char data [250];
    int animal;
    int servico;
    char pet [250];
    float tot;
    char ser [250];
    char tam;
    float pre;
    int num;
    char med [250];
    char tel [250];
    printf("Qual seu nome: ");
    fgets (nome, 250, stdin);

    printf ("Escreva a data da consulta: ");
    fgets (data, 250, stdin);

    printf ("Seu animal eh:\n");
    printf ("(1) Felino\n(2) Canino\n");
    scanf ("%i", animal);

    printf ("Servicos disponiveis:\n");
    printf ("(1) Vacina\n(2) Castracao\n(3) Venda de Racao\n(4) Medicamentos\n");
    scanf ("%i", &servico);

    printf ("Qual o nome do seu pet?");
    fgets (pet, 250, stdin);
    
    switch (servico)
    {
    case 1:
        tot = 190;
        ser = "Vacina";
        break;
    case 2: 
        if (animal == 1)
        {
            tot = 220;
        }
        else
        {
            tot = 280;
        }
        ser = "Castracao";
        break;
    case 3:
        printf ("Tamanho da ração:\n(P) Pequeno \n(M) Medio \n (G) Grande");
        scanf ("%c", tam);
        if (tam == 'P')
        {
            pre = 30;
        }
        else if (tam == 'M')
        {
            pre = 70;
        }
        else if (tam == 'G')
        {
            pre = 120;
        }
        printf ("Numero de pacotes:\n");
        scanf ("%i", &num);
        tot = pre*num;
        strcpy(ser, "Venda de racoes");
        break;
    case 4:
        tot = 0;
        ser = "Encomenda de medicamento";
        printf ("Medicamento: ");
        fgets (med, 250, stdin);
        printf ("Numero de celular");
        fgets (tel, 250, stdin);
        break;
    default:
        break;
    }
    printf ("Cliente: %s", nome);
    printf ("Servico: %s", ser);
    switch (servico)
    {
    case 1:
    case 2:
        if (animal == 1)
        {
            printf ("Felino: %s", pet);
        }
        else
        {
            printf ("Canino: %s", pet);
        }
        printf ("Data: %s", data);
        break;
    case 3:
        printf ("%i unidade(s) de tamanho %s ... %f", num, tam, pre);
        printf ("%f", tot);
        if (num > 1)
        {
            tot = tot*9/10;
            printf ("Desconto: 10%");
        }
    case 4:
        printf ("%s", med);
        printf ("Contato: %s", tel);
    
    default:
        break;
    }
    if (tot > 0)
    {
        printf ("Total: %f", tot);
    }
    return 0;
}