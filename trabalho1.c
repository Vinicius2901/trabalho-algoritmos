#include <stdio.h>
#include <string.h>

int main ()
{
    //Declaração de variáveis.
    char nome [250];//Nome do cliente.
    char data [250];//Data do serviço.
    char pet [250]; //Nome do animal.
    int animal;     //Tipo de animal.
    int servico;    //Entrada do serviço.
    float tot;      //Total a se pagar.
    char ser [250]; //Saída do serviço.
    char tam;       //Tamanho do pacote.
    float pre;      //Preço.
    int num;        //Número de ração.
    char med [250]; //Medicamento solicitado.
    char tel [250]; //Número de telefone.


    //Inputs.

    //Nome do cliente.
    printf("Qual seu nome: ");
    fgets (nome, 250, stdin);


    //Tipo de serviço.
    printf ("Servicos disponiveis:\n");
    printf ("(1) Vacina\n(2) Castracao\n(3) Venda de Racao\n(4) Medicamentos\n");
    scanf ("%i", &servico);

    
    //Casos.
    switch (servico)
    {
    case 1://Vacina.
        //Nome do pet.
        fflush (stdin);
        printf ("Qual o nome do seu pet?\n");
        fgets (pet, 250, stdin);
        //Tipo de animal.
        printf ("Seu animal eh:\n");
        printf ("(1) Felino\n(2) Canino\n");
        scanf (" %i", &animal);
        //Data da consulta.
        printf ("Escreva a data da consulta: ");
        fflush (stdin);
        fgets (data, 250, stdin);
        tot = 190;
        strcpy (ser, "Vacina");
        break;
    case 2://Castração.
        //Nome do pet.
        fflush (stdin);
        printf ("Qual o nome do seu pet?\n");
        fgets (pet, 250, stdin);
        //Tipo de animal.
        printf ("Seu animal eh:\n");
        printf ("(1) Felino\n(2) Canino\n");
        scanf (" %i", &animal);
        //Data da consulta.
        printf ("Escreva a data da consulta: ");
        fflush (stdin);
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
        
        printf ("Tamanho da racao:\n(P) Pequeno \n(M) Medio \n(G) Grande\n");
        scanf (" %c", &tam);

        printf ("Numero de pacotes:\n");
        scanf (" %i", &num);

        if (tam == 'P' || tam == 'p')
        {
            pre = 30;
        }
        else if (tam == 'M' || tam == 'm')
        {
            pre = 70;
        }
        else if (tam == 'G' || tam == 'g')
        {
            pre = 120;
        }
        tot = pre*num;
        strcpy (ser, "Venda de racoes");
        break;
    case 4://Medicamento.
        tot = 0;
        strcpy (ser, "Encomenda de medicamento");
        printf ("Medicamento: \n");
        fflush (stdin);
        fgets (med, 250, stdin);
        printf ("Numero de celular: ");
        fflush (stdin);
        fgets (tel, 250, stdin);
        break;
    default:
        break;
    }
    printf ("Cliente: %s", nome);
    printf ("Servico: %s\n", ser);
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
        printf ("%i unidade(s) de tamanho %c ... %f\n", num, tam, pre);
        printf ("%f\n", tot);
        if (num > 1)
        {
            tot = tot*9/10;
            printf ("Desconto: 10\n");
        }
        else
        {
            printf ("Desconto: 0\n");
        }
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
        printf ("Total: R$%f", tot);
    }
    return 0;
}
