#include <conio.c>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>



char usuarioAdm [10] = "ADMIN" ,senhaAdm[10] = "ADMIN";
int a, b;
bool geral = true,usuarioLogado;
int linha,coluna,z,seletorMenu;

//PROCEDIMENTOS : ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool login(a,b);
void cadastro();
void diario();
void relatorio();
void config();
void reserva();
void veiculo();
void inspecao();
void manutencao();
void sair();
void telaMenu();
void numerosMenu();
void pintaCabecalho();
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
	do{
		
		system("mode con: cols=80 lines=25");

		textcolor(WHITE);
		textbackground(BLACK);
		clrscr();

		textbackground(WHITE);

		for(int i = 0; i < 80*25; i++) {
       		printf(" ");
		}
		gotoxy(20,8);
		textcolor(BLACK);
	
		char usuario[20];
		char senha[20];
		
	   
		pintaCabecalho();
		
    	gotoxy(25,8);
    	textbackground(WHITE);
		printf("-----------------------------\n");
		gotoxy(25,9);
		printf(" *     Realizar Login     *\n");
		gotoxy(25,10);
		printf("-----------------------------\n");
		gotoxy(25,11);
		printf("Usuario : ");
		gets(usuario);
		gotoxy(25,12);
		printf("Senha : ");
		gets(senha);
		gotoxy(25,13);
		printf("------------------------------\n");
		fflush(stdin);
		
		//usuarioLogado = login(usuario,senha);
	
		if (strcmp(usuario,usuarioAdm) == 0 && strcmp(senha,senhaAdm) == 0){
			clrscr();
			pintaCabecalho();
			telaMenu();
			numerosMenu();
	    	textcolor(BLACK);
			textbackground(WHITE);
			gotoxy(1,24);
			printf("Digite a opcao desejada : ");
			scanf("%i", &seletorMenu);
			gotoxy(1,1);//ULTIMA DEFINE DE POSICAO TEM QUE ALTERAR DEPOIS <-------------------------
			fflush(stdin);
			
			
			switch (seletorMenu){
				case 1:
					cadastro();
					break;
				case 2:
					diario();
					break;
				case 3:
					relatorio();
					break;
				case 4:
					config();
					break;
				case 5:
					reserva();
					break;
				case 6:
					veiculo();
					break;
				case 7:
					inspecao();
					break;
				case 8:
					manutencao();
					break;
				case 9:
					sair();
					break;
			}
		}
	}while (geral == true);
	
    system("pause");
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void telaMenu(){
	char botoesMenu[10][10] = {"Cadastro","Diario","Relatorio","Config","Reservar","Veiculo","Inspecao","Manut.","Sair"};
    int i, j, k;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
    int consoleHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
    for (k = 0; k < 9; k++) {
        int x = (consoleWidth - 52) / 2 + (k % 3) * 18;
        int y = (consoleHeight - 18) / 2 + (k / 3) * 6;
        for (i = y + 1; i < y + 4; i++) {
            for (j = x + 1; j < x + 11; j++) {
                COORD pos = {j, i + 2};
                SetConsoleCursorPosition(hConsole, pos);
                printf(" ");
            }
        }  
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
        COORD pos = {(SHORT)(x+2), (SHORT)(y+2+2)};
        SetConsoleCursorPosition(hConsole, pos);
        printf("%s", botoesMenu[k]);
    }

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void numerosMenu(){
	int x = 1;
	int coluna,linha = 6;
	
	for (coluna = 19; coluna<60;coluna = coluna+19){
		textbackground(WHITE);
		textcolor(RED);
		gotoxy(coluna,linha);
   		printf("%i",x);
   		x++;
   		if (coluna == 57){
    		coluna = 0;
    		linha = linha + 6;
		}
		if(x == 10){
			coluna = 100;
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void pintaCabecalho() {
    textbackground(RED);
    gotoxy(1,1);
    
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 80; j++) {
            printf(" ");
     	}
    }
    gotoxy(27,2);
    printf("SISTEMA DE GESTAO DE ROTAS");
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool login(a,b){
    FILE *file;
    char line[100];

    file = fopen("cadastros", "r");

    if (file) {
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = 0;

            if (strcmp(line, a) == 0) {
                if (fgets(line, sizeof(line), file)) {
                    line[strcspn(line, "\n")] = 0;

                    if (strcmp(line, b) == 0) {
                        fclose(file);
                        return true;
                    }
                }
            }
        }
        fclose(file);
    }

 
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void cadastro(){
FILE *arquivo = fopen("cadastros.txt", "a+");

char nomeColab[50],enderecoColab[50],emailColab[50],senhaColab[10],cpfColab[11],linha[100];
int comp,compc;

clrscr();

printf("Digite o CPF do colaborador :");
gets(cpfColab);
fflush(stdin);
printf("Digite o nome do colaborador :");
gets(nomeColab);
fflush(stdin);
printf("Digite o endereco do colaborador :");
gets(nomeColab);
fflush(stdin);
printf("Digite o endereco de e-mail do colaborador :");
gets(emailColab);
fflush(stdin);
printf("Digite a senha do colaborador :");
gets(senhaColab);
fflush(stdin);


 while (fgets(linha, 100, arquivo) != NULL) {

}
fprintf(arquivo,"%s\n",&cpfColab);
fprintf(arquivo,"%s\n",&senhaColab);
fclose(arquivo);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void diario(){
clrscr();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void relatorio(){
clrscr();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void config(){
clrscr();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void reserva(){
clrscr();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void veiculo(){
clrscr();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void inspecao(){
clrscr();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void manutencao(){
clrscr();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void sair(){
	geral = false;
clrscr();
}
