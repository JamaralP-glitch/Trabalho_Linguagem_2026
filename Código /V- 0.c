#include<stdio.h>
#include<stdlib.h>


int main()
{
   
    char invest[10];
    float sabr, saliq, desc, gts, vlr_sbr, vlr_invest, percent; 
    

        printf("Informe o valor do salario Bruto: R$"); // Informe o valor bruto do Salario
         scanf("%f", &sabr);
        
        printf("Informe o valor do Salario Liquido: R$"); // informe o valor liquido
         scanf("%f", &saliq);

        printf("Informe o valor total de gastos fixo por mês: R$"); // informe os gastos fixo do mês
         scanf("%f", &gts);

        printf("Pretende investir seu salario, sim ou não? "); // informe os se tem interessi em investir
         scanf(" %c", &invest);

        desc = sabr - saliq; // Calculo para verificar o valor que é descontado

        vlr_sbr =  saliq - gts; // Calculo salario liquido subtraido com o gastos mensais




     if (invest == 'sim' && invest == 'Sim' )
        {
         printf("Quantos porcento você pretende investir:  ");
            scanf("%f", &percent);
   
                vlr_invest = (vlr_sbr * percent) / 100;

                     printf("\nValor do desconto: R$%.2f\nValor dos gastos mensais: R$%.2f\nValor da sobra do salario R$%.2f\nPorcentagem é %.2f\nValor baseado na porcentagem é R$%.2f ", desc, gts, vlr_sbr, percent, vlr_invest);
     }
     

     else 
        {
        printf("\nValor do desconto: R$%.2f\nValor dos gastos mensais: R$%.2f\nValor da sobra do salario R$%.2f", desc, gts, vlr_sbr);
     }
        



    return 0;
}
