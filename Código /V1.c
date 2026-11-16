#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float Calculo_Desconto(float sabrt, float saliq);
float Valor_Sobra(float saliq, float gts);
void Investir(int invest, float vlr_sbr, float desc, float gts, const char *nome, const char *cpf, int idade);

 void inf_finance(const char *nome, const char *cpf, int idade){
        
        int invest; // sim =  1 ou não = 0
        float sabrt, saliq, gts, desc, vlr_sbr; 

        printf("-----------Informe as finacias-------------\n");   

        printf("Informe o valor do salario Bruto: R$"); // Informe o valor bruto do Salario
         scanf("%f", &sabrt);
        
        printf("Informe o valor do Salario Liquido: R$"); // informe o valor liquido
         scanf("%f", &saliq);

        printf("Informe o valor total de gastos fixo por mês: R$"); // informe os gastos fixo do mês
         scanf("%f", &gts);

        printf("Pretende investir seu salario? sim = 1 ou não = 0  "); // informe os se tem interessi em investir 
         scanf(" %d", &invest);

        desc = Calculo_Desconto(sabrt, saliq); 

        vlr_sbr = Valor_Sobra(saliq, gts);

        Investir(invest, vlr_sbr, desc, gts, nome, cpf, idade);

}
 float Calculo_Desconto(float sabrt, float saliq){

        float desc;

        desc =  sabrt - saliq;

      return desc;
}

 float Valor_Sobra(float saliq, float gts){

        float vlr_sbr;

        vlr_sbr =  saliq - gts;
     
      return vlr_sbr;

}


void Investir(int invest, float vlr_sbr, float desc, float gts, const char *nome, const char *cpf, int idade){

    float percent, vlr_invest; 
    
     if (invest == 1)
        {
         printf("Quantos porcento você pretende investir:  ");
            scanf("%f", &percent);
   
                vlr_invest = (vlr_sbr * percent) / 100;

                     printf("\nNome: %s", nome);
                     printf("\nCPF: %s", cpf);
                     printf("\nIdade: %d", idade);
                     printf("\nValor do desconto: R$%.2f", desc);
                     printf("\nValor dos gastos mensais: R$%.2f", gts);
                     printf("\nValor da sobra do salario: R$%.2f", vlr_sbr);
                     printf("\nPorcentagem: %.2f%%", percent);
                     printf("\nValor a investir: R$%.2f\n", vlr_invest);
                                 }
                                 else{
                                       printf("\nNome: %s", nome);
                                       printf("\nCPF: %s", cpf);
                                       printf("\nIdade: %d", idade);
                                       printf("\nValor do desconto: R$%.2f", desc);
                                       printf("\nValor dos gastos mensais: R$%.2f", gts);
                                       printf("\nValor da sobra do salario: R$%.2f\n", vlr_sbr);
      }
    }



int main()
{
     int opcao, idade;
     char nome[30], cpf[15];

        printf("-------------Informações---------------\n");

        printf("Informe seu nome: ");
        scanf(" %29[^\n]", nome);

        printf("\nInforme seu CPF: ");
        scanf("%14s",  cpf);

        printf("\nInforme sua idade:");
        scanf("%d", &idade);


    do
    {printf("--------- Manu ----------------\n");
     printf("1 Auxilio financeiro\n");
     printf("0 Sair\n");
     printf("Escolha:");
     scanf("%d", &opcao);

     if (opcao == 1){
        inf_finance(nome,cpf, idade);

       }else if (opcao != 0){
         printf("Opção invalida\n");
    }
     

    
    } while (opcao != 0);

    printf("Fim do programa.\n");

    return 0;
     }
