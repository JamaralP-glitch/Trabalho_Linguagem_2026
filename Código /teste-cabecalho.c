int main(){
        char nome[15], confirm;
        int CPF;
        float gastos, sobra, salario;

        printf("Informe seu PRIMEIRO nome: ");
        fflush(stdin);
         scanf(" %14s",nome);

        printf("\nInforme seu CPF: ");
         scanf("%d", &CPF);

        printf("\nInfomrme seu salario: ");
         scanf("%f",&salario);

        printf("\nInforme seus gastos mensais: ");
         scanf("%f",&gastos);

        sobra = (salario - gastos);

        printf("\nA quantidade disponivel para uso: %.2f \n", sobra);

        printf("\nCom a quantida informada que esta disponivel, planeja investir?(s = sim e n = nao)\n");
        scanf(" %c",&confirm);


        if(confirm == 's'  confirm == 'S'){
            printf("Ok, vamos iniciar!\n");
        }
        else if(confirm == 'n'  confirm == 'N'){
            printf("Positivo, some daqui!\n");
        }
        else{
            printf("Escolha uma das opcoes corretas!\n");
            scanf(" %c", &confirm);
    }

    printf("aaaaa");

return 0;
}
