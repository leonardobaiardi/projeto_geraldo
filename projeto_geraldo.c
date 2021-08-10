/*
Programa para gestão de casas de aluguel
Funcionalidades: Cadastra, visualiza dados, edita dados, apaga e busca inquilinos, gera relatórios
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

/* Definição de constantes */
#define N 100

/* Definição de estruturas */
typedef struct {
	char nomeInq[N];
	int idadeInq;
	char ruaInq[N];
	int numCasaInq;
	char bairroInq[N];
	int rg;
	int cpf;
	int dataPagamento;
	char dataInicioContrato[6];
	char dataFinalContrato[11];
	int numRegistroSabesp;
	int numRegistroEnel;
}varInquilino;

/* Variáveis globais */
varInquilino inquilino[N];

/* Prototipação de funções */
int main(void);
void menu(void);
void cadastraInquilino();   
void consultaInquilino();   
void editaDadosInquilino(); 
void geraRelatorio();
void visualizaRelatorio();

/* Construção de funções */
void menu (void){
	char opc;
	do{
	system("mode 48, 18"); system("color F0");
	printf("\n ============================================");
	printf("\n        GESTÃO DAS CASAS DE GERALDO	       ");
	printf("\n ============================================");
	printf("\n      1. Cadastra novo inquilino             ");
	printf("\n      2. Busca dados de inquilino            ");
	printf("\n      3. Editar os dados de um inquilino     ");
	printf("\n      4. Gera relatório de inquilinos        ");
	printf("\n      5. Visualiza relatório de inquilinos   ");
	printf("\n      F. Sair do programa                    ");
	printf("\n ============================================");
	printf("\n     Escolha: "); fflush(stdin); opc=getche();
	switch(opc) {
		case '1' : {cadastraInquilino();   break;}
		case '2' : {consultaInquilino();   break;}
		case '3' : {editaDadosInquilino(); break;}
		case '4' : {geraRelatorio();       break;}
		case '5' : {visualizaRelatorio();  break;}
		case 'f' : exit(0);
		case 'F' : exit(0);
	}
	if(opc<'1'||opc>'5'){
		printf("\n ERRO! ESCOLHA UMA OPÇÃO VÁLIDA!\n APERTE QUALQUER TECLA PARA TENTAR NOVAMENTE"); 
		fflush(stdin); getch(); system("cls");
		} 
	}while(opc<'1'||opc>'5');
}

void cadastraInquilino(){
	char opc;
	int i, j;
	do{
		system("cls"); system("color 1f"); system("mode 100, 20");
		printf("\n Você deseja cadastrar quantos inquilinos?\n\n 1) Apenas um.\n 2) Mais de um.\n 3) Retornar ao menu.\n ");
		fflush(stdin); opc=getche();
		switch(opc){
			case '1' : {
						system("cls"); 
						printf("\n Insira o nome do inquilino: "); 								fflush(stdin); gets(inquilino[j].nomeInq);
						printf("\n Insira a idade do inquilino: ");								fflush(stdin); scanf("%d", &inquilino[j].idadeInq);
						printf("\n Insira o nome da rua da casa de aluguel: ");					fflush(stdin); gets(inquilino[j].ruaInq);
						printf("\n Insira o número da casa de aluguel: ");					    fflush(stdin); scanf("%d", &inquilino[j].numCasaInq);
						printf("\n Insira o bairro da casa de aluguel: ");				    	fflush(stdin); gets(inquilino[j].bairroInq);
						printf("\n Insira o RG do inquilino (APENAS NÚMEROS): ");				fflush(stdin); scanf("%d", &inquilino[j].rg);
						printf("\n Insira o CPF do inquilino (APENAS NÚMEROS): ");				fflush(stdin); scanf("%d", &inquilino[j].cpf);
						printf("\n Insira a data de pagamento do aluguel (APENAS O DIA): ");	fflush(stdin); scanf("%d", &inquilino[j].dataPagamento);
						printf("\n Insira a data do início do contrato (FORMATO XX/XX/XXXX): ");fflush(stdin); gets(inquilino[j].dataInicioContrato);
						printf("\n Insira a data do final do contrato  (FORMATO XX/XX/XXXX): ");fflush(stdin); gets(inquilino[j].dataFinalContrato);
						printf("\n Insira o número de registro da SABESP: ");	        		fflush(stdin); scanf("%d", &inquilino[j].numRegistroSabesp);
						printf("\n Insira o número de instalação da ENEL: ");			        fflush(stdin); scanf("%d", &inquilino[j].numRegistroEnel);
						printf("\n Informações registradas!\n Aperte qualquer tecla para voltar ao menu."); getch(); menu(); break;
					}
			case '2' : {
						system("cls"); system("mode 100, 28"); printf("\nInsira a quantidade de inquilinos que serão cadastrados: ");
						fflush(stdin); scanf("%i", &j); printf("\nAperte qualquer tecla para começar o cadastramento\n"); getch();
						for(i=0;i<j;i++){
						system("cls"); printf("\nInquilino %d\n", i+1);
						printf("\n Insira o nome do inquilino: "); 								fflush(stdin); gets(inquilino[i].nomeInq);
						printf("\n Insira a idade do inquilino: ");								fflush(stdin); scanf("%d", &inquilino[i].idadeInq);
						printf("\n Insira o nome da rua da casa de aluguel: ");					fflush(stdin); gets(inquilino[i].ruaInq);
						printf("\n Insira o número da casa de aluguel: ");					    fflush(stdin); scanf("%d", &inquilino[i].numCasaInq);
						printf("\n Insira o bairro da casa de aluguel: ");				    	fflush(stdin); gets(inquilino[i].bairroInq);
						printf("\n Insira o RG do inquilino (APENAS NÚMEROS): ");				fflush(stdin); scanf("%d", &inquilino[i].rg);
						printf("\n Insira o CPF do inquilino (APENAS NÚMEROS): ");				fflush(stdin); scanf("%d", &inquilino[i].cpf);
						printf("\n Insira a data de pagamento do aluguel (APENAS O DIA): ");	fflush(stdin); scanf("%d", &inquilino[i].dataPagamento);
						printf("\n Insira a data do início do contrato (FORMATO XX/XX/XXXX): ");fflush(stdin); gets(inquilino[i].dataInicioContrato);
						printf("\n Insira a data do final do contrato  (FORMATO XX/XX/XXXX): ");fflush(stdin); gets(inquilino[i].dataFinalContrato);
						printf("\n Insira o número de registro da SABESP: ");	        		fflush(stdin); scanf("%d", &inquilino[i].numRegistroSabesp);
						printf("\n Insira o número de instalação da ENEL: ");			        fflush(stdin); scanf("%d", &inquilino[i].numRegistroEnel);
						} printf("\n Informações registradas!\n Aperte qualquer tecla para voltar ao menu."); getch(); menu(); break;
 					}	
 			case '3' : menu(); break;
 		}
 		if(opc!='1' && opc != '2' && opc != '3'){
 			printf("OPÇÃO INVÁLIDA! ESCOLHA 1, 2 ou 3\n APERTE QUALQUER TECLA PARA TENTAR NOVAMENTE"); getch();	
		 }
 	}while(opc!='1' && opc != '2' && opc != '3');
}


void consultaInquilino(){
	
}

void editaDadosInquilino(){
	
}

void geraRelatorio(){
	
}

void visualizaRelatorio(){
	
}

/* Corpo do programa */
int main(void){
	setlocale(LC_ALL, "");
	menu();
	
	return(0);
}


