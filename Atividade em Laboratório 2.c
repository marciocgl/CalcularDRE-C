#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>


void PermitirCaracterEspecial()
{

    setlocale(LC_ALL, "Portuguese"); //Acrescentar caracteres da língua portuguesa, ç,acentos,etc ...
};

void Login(char login[15], char senha[15])
{

    PermitirCaracterEspecial();
    printf("\n");
    printf(" ___________________________\n");
    printf("|Demonstração de Resultado: |\n");
    printf("|___________________________|");
    printf("\n|login: ");
    scanf("%s",login);
    printf("|___________________________|");
    printf("\n|Senha: ");
    scanf("%s",senha);
    printf("|___________________________|");
    printf("\n");
    system("cls");
}


void ExibirMenu1(int ano)
{
    PermitirCaracterEspecial();
    system("color f2");
    printf("\n ________________________________________________\n");
    printf("|                   BEM VINDO !                  |\n");
    printf("|------------------------------------------------|\n");
    printf("|                   DRE  %d                    |\n",ano);
    printf("|------------------------------------------------|\n");
    printf("| 1 - Receita Bruta                              |\n");
    printf("|------------------------------------------------|\n");
    printf("| 2 - Venda(s) Cancelada(s)                      |\n");
    printf("|------------------------------------------------|\n");
    printf("| 3 - Desconto(s)                                |\n");
    printf("|------------------------------------------------|\n");
    printf("| 4 - Imposto Sobre Vendas                       |\n");
    printf("|------------------------------------------------|\n");
    printf("| 5 - Receita Líquida                            |\n");
    printf("|------------------------------------------------|\n");
    printf("| 6 - Custo de Mercadorias Vendidas              |\n");
    printf("|------------------------------------------------|\n");
    printf("| 7 - Lucro Bruto                                |\n");
    printf("|------------------------------------------------|\n");
    printf("| 8 - Despesas Com Vendas                        |\n");
    printf("|------------------------------------------------|\n");
    printf("| 9 - Despesas Administrativas                   |\n");
    printf("|------------------------------------------------|\n");
    printf("| 10 - Despesas Operacionais                     |\n");
    printf("|------------------------------------------------|\n");
    printf("| 11 - Lucro Operacional                         |\n");
    printf("|------------------------------------------------|\n");
    printf("| 12 - Receitas Financeiras                      |\n");
    printf("|------------------------------------------------|\n");
    printf("| 13 - Despesas Financeiras                      |\n");
    printf("|------------------------------------------------|\n");
    printf("| 14 - Resultado Financeiro                      |\n");
    printf("|------------------------------------------------|\n");
    printf("| 15 - Outras Receitas e Despesas                |\n");
    printf("|------------------------------------------------|\n");
    printf("| 16 - Lucro Liquido Antes do Imposto de Renda   |\n");
    printf("|------------------------------------------------|\n");
    printf("| 17 - Imposto de Renda e Contribuiçao Social    |\n");
    printf("|------------------------------------------------|\n");
    printf("| 18 - Lucro Liquido Depois do Imposto de Renda  |\n");
    printf("|------------------------------------------------|\n");
    printf("| 19 - Sair                                       |\n");
    printf("|________________________________________________|\n");
}



void SubMenu()
{

    printf("\n\n\n");
    printf("               ________________________________________________________\n");
    printf("              |                           |                            |\n");
    printf("              |                           |                            |\n");
    printf("              |       19- Para Sair       |  Pressione Qualquer Número |\n");
    printf("              |                           |    Para Voltar ao Menu...  |\n");
    printf("              |___________________________|____________________________|\n");

}


typedef struct Usuarios
{
    char login[15];
    char senha[15];
} Usuarios;

int main ()
{
//Criando um Login de usúrio
    Usuarios u1 ;
    strcpy(u1.login, "adm");
    strcpy(u1.senha, "1234");

    int loginAutenticado = -1 ;
    char login[15], senha[15];
    int ano ;
    int opc ;
    float receitaBruta = 0, vendasCanc = 0, desc = 0, impostSvendas = 0, receitaLiq = 0,
          custMercVend =0, lucroBrut =0, despOp =0, despCvend =0, despAdm, lucroOp =0,
          resultFinan =0, receitFinan =0, despFinan =0, outrasRectEdesp =0, lucroLiquidAntesIMPR =0,
          impostDeRend =0, lucroLiquidDepoisIMPR =0;


    FILE * arq;
    arq = fopen("DRE.txt","a");
    if(arq == NULL)
    {
        printf("Nao foi Possivel Acessar o arquivo: ");
        exit(0);
    }

    while (loginAutenticado != 1 )   //Se repetir até login existir
    {

        Login(login,senha); //fazendo login
        printf("\nVerifificando usuário, Por Favor Aguarde ...\n");
        // Sleep(2000);
        system("cls");
        if ( strcmp(u1.login,login) == 0 && strcmp(u1.senha,senha)  == 0 )   //caso login exista, executa alguma coisa
        {

            loginAutenticado = 1 ;

            // printf("Logado com Sucesso ...");
            // Sleep(2000);
            system("cls");

            printf("Digite o ano: ");
            scanf("%d",&ano);
            system("cls");
            do
            {
                ExibirMenu1(ano);
                scanf("%d",& opc);
                system("cls");
                switch (opc)
                {

                case 1 :

                    printf("Digite o valor da Receita Bruta: ");
                    scanf("%f",&receitaBruta);

                    break ;

                case 2 :

                    printf("Digite o valor das Vendas Canceladas: ");
                    scanf("%f",&vendasCanc);

                    break ;

                case 3 :

                    printf("Digite o valor dos Descontos: ");
                    scanf("%f",&desc);

                    break ;

                case 4 :

                    printf("Digite o valor do Imposto Sobre Vendas: ");
                    scanf("%f",&impostSvendas);

                    break ;

                case 5 :


                    receitaLiq = receitaBruta - (vendasCanc+desc+impostSvendas);

                    printf("\n\tReceita Liquida: %0.2f",receitaLiq);

                    SubMenu();
                    scanf("%d",& opc);
                    system("cls");

                    break ;

                case 6 :

                    printf("Custo De Mercadorias Vendidas: ");
                    scanf("%f",&custMercVend);

                    break ;

                case 7 :

                    lucroBrut = receitaLiq - custMercVend;

                    printf("\n\tLucro Bruto: %0.2f",lucroBrut);

                    SubMenu();
                    scanf("%d",& opc);
                    system("cls");

                    break ;


                case 8 :

                    printf("Despesas Com Vendas: ");
                    scanf("%f",&despCvend);

                    break ;

                case 9 :

                    printf("Despesas Administrativas: ");
                    scanf("%f",&despAdm);

                    break ;

                case 10 :

                    despOp = despCvend + despAdm;

                    printf("\n\tDespesas Operacionais: %0.2f",despOp);

                    SubMenu();
                    scanf("%d",& opc);
                    system("cls");

                    break;

                case 11 :

                    lucroOp = lucroBrut - despOp;
                    printf("\n\tLucro Operacional: %0.2f",lucroOp);

                    SubMenu();
                    scanf("%d",& opc);
                    system("cls");

                    break ;

                case 12 :
                    printf("Receita Financeira: ");
                    scanf("%f",&receitFinan);

                    break ;

                case 13 :

                    printf("Despesas Financeiras: ");
                    scanf("%f",&despFinan);

                    break ;

                case 14 :

                    resultFinan = despFinan - receitFinan ;
                    printf("\n\tResultado Financeiro: %0.2f",resultFinan);

                    SubMenu();
                    scanf("%d",& opc);
                    system("cls");

                    break ;

                case 15 :

                    printf("Outras Receitas e Despesas: ");
                    scanf("%f",&outrasRectEdesp);

                    break ;

                case 16 :

                    lucroLiquidAntesIMPR = (lucroOp - resultFinan) + outrasRectEdesp;

                    printf("\n\tLucro Liquido Antes do Imposto de Renda: %0.2f",lucroLiquidAntesIMPR);

                    SubMenu();
                    scanf("%d",& opc);
                    system("cls");

                    break ;

                case 17 :

                    printf("Imposto De Renda e Contribuição Social: ");
                    scanf("%f",&impostDeRend);

                    break ;

                case 18 :

                    lucroLiquidDepoisIMPR = lucroLiquidAntesIMPR - impostDeRend;

                    printf("\n\tLucro Liquido Depois do Imposto de Renda: %0.2f",lucroLiquidDepoisIMPR);

                    SubMenu();
                    scanf("%d",& opc);
                    system("cls");

                    break ;

                case 19 :

                    printf("\t\nSalvando ...");
                    Sleep(2000);
                    system("cls");
                    fprintf(arq,"\n");
                    fprintf(arq,"________________________________________________________________");
                    fprintf(arq,"\nDEMONSTRATIVO FINANCEIRO (DRE) | %d\n",ano);
                    fprintf(arq,"________________________________________________________________\n");
                    fprintf(arq,"    Receita Operacional Bruta                           %02.f\n",receitaBruta);
                    fprintf(arq,"________________________________________________________________\n");
                    fprintf(arq," -  Vendas canceladas      	                        %02.f\n",vendasCanc);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq," -  Descontos       	                                %02.f\n",desc);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq," -  Impostos sobre vendas     	                        %02.f\n",impostSvendas);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq," =  Receita líquida      	                        %02.f\n",receitaLiq);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq," -  Custos sobre mercadorias                            %02.f\n",custMercVend);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq," =  Lucro Bruto      	                                %02.f\n",lucroBrut);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq," -  Despesas Operacionais                               %02.f\n",despOp);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq,"       Despesas com vendas                              %02.f\n",despCvend);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq,"       Despesas Administrativas      	                %02.f\n",despCvend);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq," =     Lucro  Operacional      	                        %02.f\n",lucroOp);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq,"(+/-)  Resultado Financeiro      	                %02.f\n",resultFinan);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq,"         (+) Receitas financeiras      	                %02.f\n",receitFinan);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq,"         (-) Despesas financeiras      	                %02.f\n",despFinan);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq," -  Outras receitas e despesas       	                %02.f\n",outrasRectEdesp);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq,"(+/-)  Lucro Líquido antes do imposto de renda          %02.f\n",lucroLiquidAntesIMPR);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq," -  Imposto de renda e contribuição social      	%02.f\n",impostDeRend);
                    fprintf(arq,"----------------------------------------------------------------\n");
                    fprintf(arq," =  Lucro líquido depois do imposto de renda      	%02.f\n",lucroLiquidDepoisIMPR);
                    fprintf(arq,"----------------------------------------------------------------\n\n");


                    printf("\t\nSaindo ...");
                    Sleep(2000);
                    system("cls");
                    printf("\n\n");
                    //  system("pause");

                    break ;

                default :

                    printf("\nOpção Inválida !!!\nPor Favor Digite A opção desejada de 1 a 19. \n");

                    break ;
                }


            }
            while(opc != 19);

            fclose(arq);

        }
        else
        {

            printf("\nLogin inexistente!!!\n");

            loginAutenticado = 0;

            printf("\nPor Favor Tente Novamente !...\n");
            Sleep(2000);
            system("cls");
        }
    }

    return 0;
}

