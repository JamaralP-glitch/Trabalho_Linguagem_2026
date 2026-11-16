  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>
  #include <locale.h>
  
  // Prototipos
  float Calculo_Desconto(float sabrt, float saliq);
  float Valor_Sobra(float saliq, float gts);
  void Investir(int invest, float vlr_sbr, float desc, float gts, const char *nome, const char *cpf, int idade);
   void Emprestimo(const char *nome, const char *cpf, int idade);

  void inf_finance(const char *nome, const char *cpf, int idade){
          
          int invest; // sim =  1 ou não = 0
          float sabrt, saliq, gts, desc, vlr_sbr; 

          printf("-----------Informe as finanças-------------\n");   

          printf("Informe o valor do Salário Bruto: R$"); // Informe o valor bruto do Salario
          scanf("%f", &sabrt);
          
          printf("Informe o valor do Salário Líquido: R$"); // informe o valor liquido
          scanf("%f", &saliq);

          printf("Informe o valor total de gastos fixos por mês: R$"); // informe os gastos fixo do mês
          scanf("%f", &gts);
          
          desc = Calculo_Desconto(sabrt, saliq); 

          vlr_sbr = Valor_Sobra(saliq, gts);
          
          printf("\nConfira o valor que esta disponivel para investir: %R$.2f\n",vlr_sbr);

          printf("\nPretende investir seu salário? sim = 1 ou não = 0  "); // informe os se tem interessi em investir 
          scanf(" %d", &invest);

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
            if (vlr_sbr <= 0)
                {
                  printf("\nNão pode investir: seus gastos são maiores ou iguais a seu salário líquido.\n");
                  return;
                    }
                      printf("\nQuantos por cento (%%) você pretende investir?");
                      scanf("%f", &percent);
                      if (percent <= 0 || percent > 100)
                      {
                        printf("\nPorcentagem inválida. Digite um valor entre 0 e 100.\n");
                        return;
                      }
                      
                    
                      vlr_invest = (vlr_sbr * percent) / 100;

                      printf("-------------- Resumo ------------------\n");
                      printf("\nNome: %s", nome);
                      printf("\nCPF: %s", cpf);
                      printf("\nIdade: %d", idade);
                      printf("\nValor do desconto: R$%.2f", desc);
                      printf("\nValor dos gastos mensais: R$%.2f", gts);
                      printf("\nValor da sobra do salário: R$%.2f", vlr_sbr);
                      printf("\nPorcentagem: %.2f%%", percent);
                      printf("\nValor a investir: R$%.2f\n", vlr_invest);
                                  }else{
                                        printf("-------------- Resumo ------------------\n");
                                        printf("\nNome: %s", nome);
                                        printf("\nCPF: %s", cpf);
                                        printf("\nIdade: %d", idade);
                                        printf("\nValor do desconto: R$%.2f", desc);
                                        printf("\nValor dos gastos mensais: R$%.2f", gts);
                                        printf("\nValor da sobra do salário: R$%.2f\n", vlr_sbr);
        }
      }

  void Emprestimo(const char *nome, const char *cpf, int idade){
    float valor, juros, taxa, fator = 1.0, parcela, total, saldo, jurosMes;
    int meses, i;

    printf("-------------- Simulador de Empréstimo ------------\n");

    printf("Valor do empréstimo: R$ ");
    scanf("%f", &valor);

    printf("Informe os juros ao mês (%%): ");
    scanf("%f", &juros);

    printf("Informe o número de parcelas: ");
    scanf("%d", &meses);

    if (valor <= 0 || juros < 0 || meses <= 0)
    {
      printf("\nValores inválidos.\n");
      return;   
    }
    
     taxa = juros / 100; // o valor em % vira 0.05

    // for 1: calcula (1 + taxa) elevado ao numero de meses

    for ( i = 0; i < meses; i++)
    {
      fator *= (1 + taxa);
    }
     if (taxa == 0){
        parcela = valor / meses;
     }else{
        parcela = valor * taxa * fator / (fator - 1);
        }

      total = parcela * meses;

    printf("Nome: %s\n",nome);
    printf("CPF: %s\n", cpf);
    printf("Idade: %d\n", idade);
    printf("Valor emprestado: R$ %.2f\n", valor);
    printf("Total a pagar: R$ %.2f\n", total);
    printf("Prazo: %d meses\n", meses);
    printf("Parcela mensal: R$ %.2f\n", parcela);
    printf("Total de juros: R$ %.2f\n", total - valor);


    // for 2: mes a mes
    printf("\n===== MÊS A MÊS =====\n");
    saldo = valor;
    for (i = 1; i <= meses; i++)
    {
        jurosMes = saldo * taxa;
        saldo = saldo + jurosMes - parcela;
        if (saldo < 0.005) saldo = 0;   // evita -0.00
        printf("Mês %2d | Juros: R$ %8.2f | Saldo devedor: R$ %10.2f\n",
               i, jurosMes, saldo);
    }
  }

  int main()
  {
  	setlocale(LC_ALL, "Portuguese_Brazil"); // código para a gramática
  	
      int opcao, idade;
      char nome[30], cpf[15];

          printf("-------------Informações---------------\n");

          printf("Informe seu nome: ");
          scanf(" %29[^\n]", nome);

          printf("\nInforme seu CPF: ");
          scanf("%14s",  cpf);

          printf("\nInforme sua idade: ");
          scanf("%d", &idade);


      do
      {printf("--------- Menu ----------------\n");
      printf("1-Auxílio financeiro\n");
      printf("2-Simulação para empréstimo\n");
      printf("0-Sair\n");
      printf("Escolha: ");
      scanf("%d", &opcao);

      if (opcao == 1){
          inf_finance(nome,cpf, idade);

        }else if (opcao == 2){
          Emprestimo(nome, cpf, idade);

        }else if (opcao != 0){
          printf("Opção inválida\n");
      }
      

      
      } while (opcao != 0);

      printf("Fim do programa.\n");

      return 0;
      }
