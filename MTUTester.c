/*
MTUTester
Code written by Luciano Rovanni do Nascimento.
08/17/2019
Version 3.0 02/17/2020
GNU General Public License v3.0 - GNU GPLv3
Permissions of this strong copyleft license are conditioned on making available complete source code of licensed works and modifications, which include larger works using a licensed work, under the same license. Copyright and license notices must be preserved. Contributors provide an express grant of patent rights.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //necessario para strcpy
#include <time.h> //necessario para usar localtime() e struct tm
#include <locale.h>//necessario para usar setlocale
int main()
{
	setlocale(LC_ALL, "Portuguese");	
	time_t now;
	struct tm  ts;
	char       buf[80]="", data[80]="";
	
	// Obtem o tempo corrente
	now = time(NULL);
	
	// Formata e imprime o tempo, "ddd yyyy-mm-dd hh:mm:ss zzz"
	ts = *localtime(&now);
	strftime(buf, sizeof(buf), "Dia: %d/%m/%Y - Hora: %H:%M:%S", &ts);
	// Cria um relatorio com nome: teste_mtu.txt e insere dia e hora
	strcat(buf, " > teste_mtu.txt");
	strcat(data, "echo ");
	strcat(data, buf);			
    system(data);				
	printf("Medidor de MTU");
	int i;
	int inicio=1450;
	int fim=1400;
	int opcao;	
	char t_mtu [6];
	char site00[60] = "";	
	char site[60] = "";	
	// Opcoes para escolher site para testar MTU
	printf ("\nDigite um valor de 1 a 4: \n");
	printf ("1 - Para pingar no site do Google.\n");	
	printf ("2 - Para pingar no site do Yahoo.\n");
	printf ("3 - Para pingar no site do Uol.\n");	
	printf ("4 - Para sair.\n");		
	scanf("%i", &opcao);		
	switch (opcao){
		case 1:
			strcpy(site, "ping google.com -n 1 -f -l ");
			break;
		case 2:
			strcpy(site, "ping www.yahoo.com.br -n 1 -f -l ");
			break;
		case 3:
			strcpy(site, "ping www.uol.com.br -n 1 -f -l ");
			break;
		case 4:
			exit(0);
			break;							
	}
	// Opcoes para escolher o intervalo a ser testado
	printf ("\nDigite um valor de 1 a 3: \n");
	printf ("1 - Para testar MTU 1500 at� 1400\n");	
	printf ("2 - Para testar MTU 1500 at� 1450\n");
	printf ("3 - Para testar MTU 1500 at� 1480\n");	
	printf ("4 - Para sair.\n");		
	scanf("%i", &opcao);		
	switch (opcao){
		case 1:
			inicio=1500;
			fim=1400;
			break;
		case 2:
			inicio=1500;
			fim=1450;
			break;		
		case 3:
			inicio=1500;
			fim=1480;
			break;
		case 4:
			exit(0);
			break;						
	}	
	
	for(i = inicio; i >= fim; i--)
	{
			printf("\nTamanho MTU: %i a ser testado.\n",i);
			strcpy(site00, site);			
			// Iinteiro para string. Ate 10 algarismos.			
			sprintf(t_mtu, "%i", i);			
			strcat(site00, t_mtu);
			// Armazena as informacoes coletadas do testes no relatorio com nome: teste_mtu.txt 
			strcat(site00, " >> teste_mtu.txt");			
			printf("\nComando utilizado: %s\n",site00);			
			system (site00);		   	
	}
	// Abre o relatorio no notepad	
	system("start notepad teste_mtu.txt");
	return 0;
	exit(0);
}
