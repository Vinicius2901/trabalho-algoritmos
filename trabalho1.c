#include <stdio.h>
#include <string.h>

int main ()
{
    //Declaração de variáveis
    char nome [250];//Nome do cliente
    char data [250];//Data do serviço
    char pet [250]; //Nome do animal
    int animal;     //Tipo de animal
    int servico;    //Entrada do serviço
    float tot;      //Total a se pagar
    char ser [250]; //Saída do serviço
    char tam;       //Tamanho do pacote
    float pre;      //Preço
    int num;        //Número de ração
    char med [250]; //Medicamento solicitado
    char tel [250]; //Número de telefone


    //Inputs

    //Nome do cliente
    printf("Qual seu nome: ");
    fgets (nome, 250, stdin);

    //Data da consulta
    printf ("Escreva a data da consulta: ");
    fgets (data, 250, stdin);

    //Nome do pet
    printf ("Qual o nome do seu pet?\n");
    fgets (pet, 250, stdin);

    //Tipo de animal
    printf ("Seu animal eh:\n");
    printf ("(1) Felino\n(2) Canino\n");
    scanf ("%i", &animal);

    //Tipo de serviço
    printf ("Servicos disponiveis:\n");
    printf ("(1) Vacina\n(2) Castracao\n(3) Venda de Racao\n(4) Medicamentos\n");
    scanf ("%i", &servico);

    
    //Casos
    switch (servico)
    {
    case 1://Vacina
        tot = 190;
        strcpy (ser, "Vacina");
        break;
    case 2://Castração
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
    case 3://Venda de ração
        printf ("Tamanho da racao:\n(P) Pequeno \n(M) Medio \n(G) Grande\n");
        scanf ("%c", &tam);
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
        strcpy (ser, "Venda de racoes");
        break;
    case 4://Medicamento
        tot = 0;
        strcpy (ser, "Encomenda de medicamento");
        printf ("Medicamento: \n");
        fgets (med, 250, stdin);
        printf ("Numero de celular: ");
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
