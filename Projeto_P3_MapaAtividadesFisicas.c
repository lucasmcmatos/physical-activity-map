#include <stdio.h>
#include <stdlib.h>

int state;

// type of activities:
//(0) - Caminhada
//(1) - Bicicleta
//(2) - Natação
//(3) - Musculação
//(4) - Dança

struct Activity{
	int type;
	float duration;
	float caloriesLost;
};

struct Day{
	char date[8];
	float caloriesTotal;
	struct Activity activities[3];
};

struct User{
	char username[30];
	char password[30];
	int height;
	float initialWeight;
	struct Day days[7];
}user;

void welcome(){
	printf("================================\n\n");
		printf("Mapa de Atividades Fisicas\n\n");
		printf("(-1) - Desligar Server.\n");
		printf("(1) - Entrar na 'Pagina de Cadastro'.\n");
		printf("(2) - Entra na 'Pagina de Login'.");	
	printf("\n\n================================\n");
}

void registerPage(){
	printf("================================\n\n");
		printf("Pagina de 'Cadastro'\n\n");
		printf("(0) - Voltar ao inicio.\n");
		printf("(1) - Cadastrar.\n");
		printf("(2) - Entra na 'Pagina de Login'.");
		
	printf("\n\n================================\n");
}

void registerFunction(){
	printf("================================\n\n");
		printf("Digite o 'Username', 'Senha', 'Altura' e 'Peso Inicial' para cadastro.");
		printf("\n[SEM caracteres especiais ou acentos]");
	printf("\n\n================================\n");
}

void loginPage(){
	printf("================================\n\n");
		printf("Pagina de 'Login'\n\n");
		printf("(0) - Voltar ao inicio.\n");
		printf("(1) - Entrar na 'Pagina de Cadastro'.\n");
		printf("(2) - Logar.");
	printf("\n\n================================\n");	
}

void loginFunction(){
	printf("================================\n\n");
		printf("Digite o 'Username' e 'Senha' para login.");
		printf("\n[SEM caracteres especiais ou acentos]");
	printf("\n\n================================\n");	
}

int verifyLogin(){
	
	
	char usernameTemp[30];
	char passwordTemp[30];
	int i ;
			
	loginFunction();
	printf("Username: ");
	scanf("%s", &usernameTemp);
	printf("Senha: ");
	scanf("%s", &passwordTemp);
	
	system("cls");
	
	int stateUser , statePassword;
	
	for( i=0 ; i<30 ; i++ ){
		if(user.username[i] != NULL){
			if(usernameTemp[i]  == NULL){
				stateUser = 0;
				break;
			}else{
				if(usernameTemp[i] != user.username[i]){
					stateUser = 0;
					break;
				}else{
					stateUser = 2;	
				}
			}
		}else{
			if(usernameTemp[i]  == NULL){
				if(i==0){
					stateUser = 0;
					break;
				}else{
					stateUser = 2;
					break;
				}
			}else{
				stateUser = 0;
				break;
			}	
		}			
	}
	
	for( i=0 ; i<30 ; i++){
		if(user.password[i] != NULL){
			if(passwordTemp[i] == NULL){
				statePassword = 0;
				break;
			}else{
				if( user.password[i] != passwordTemp[i] ){
					statePassword = 0;
					break;
				}else{
					statePassword = 2;
				}
			}
		}else{
			if(passwordTemp[i] == NULL){
				if(i==0){
					statePassword = 0;
					break;
				}else{
					statePassword = 2;
					break;
				}
			}else{
				statePassword = 0;
				break;
			}
		}
	}
	
	if(statePassword == stateUser){
		if(stateUser == 0){
			return 0;
		} else{
			return 2;
		}
	}else{
		return 0;
	}
	
}

void loggedPage(){
	printf("================================\n\n");
		printf("Pagina 'Logada'\n\n");
		printf("(0) - Vizualizar 'Atividades Fisicas' e 'Progresso Atual'.\n");
		printf("(1) - Deslogar");
	printf("\n\n================================\n");	
}

void showActivities(){
	printf("================================\n\n");
		printf("Pagina das 'Atividades'\n\n");
		
	printf("\n\n================================\n");	
}

int main(void) {
	
	while(state != -1){
		
		if(state == 0){
			
			//HOME PAGE
			welcome();
			printf("Digite sua escolha: ");
			scanf("%d", &state);
			system("cls");
			//HOME PAGE
			
		}else if(state == 1){
			registerPage();
			printf("Digite sua escolha: ");
			scanf("%d", &state);
			system("cls");
			
			if(state == 1){
				
				//CADASTRO DE NOVO USUARIO
				registerFunction();
				printf("Username: ");
				scanf("%s", &user.username);
				printf("Senha: ");
				scanf("%s", &user.password);
				printf("Altura (cm): ");
				scanf("%d", &user.height);
				printf("Peso inicial (Kg): ");
				scanf("%f", &user.initialWeight);
				system("cls");
				printf("================================\n\n");
				printf("Usuario Cadastrado\n\n");
				state = 0;
				//CADASTRO DE NOVO USUARIO
				
			}
			
			
		}else if(state == 2){
			
		
			loginPage();
			printf("Digite sua escolha: ");
			scanf("%d", &state);
			system("cls");
			
			
			
			if(state == 2){
				
				//VERIFICACAO DE LOGIN
				state = verifyLogin();
				
				if(state == 2){
					printf("================================\n\n");
					printf("Usuario Logado\n\n");
				}else{
					printf("================================\n\n");
					printf("Username ou Senha incorreto.\n\n");	
				}
				//VERIFICACAO DE LOGIN
				
				//USUARIO LOGADO
				if(state == 2){
					int i , j;
					int stateLogged = 0;
					
					while(stateLogged != -1){
						
						if(stateLogged == 0){
							
							loggedPage();
							printf("Digite sua escolha: ");
							scanf("%d", &stateLogged);
							system("cls");
							
							if(stateLogged == 0){
								//VIZUALIZAÇÃO DAS ATIVIDADES
								showActivities();
								printf("Digite sua escolha: ");
								scanf("%d", &stateLogged);
								system("cls");
								//VIZUALIZAÇÃO DAS ATIVIDADES
							}
							
						}else if(stateLogged == 1){
							printf("================================\n\n");
							printf("Tem certeza?\n\n");
							printf("(-1) - Sim\n");
							printf("(2) - Nao");
							printf("\n\n================================\n");
							printf("Digite sua escolha: ");
							scanf("%d", &state);
							
							if(state == -1){
								stateLogged = -1;
							}else{
								stateLogged = 0;
							}
							
							system("cls");
						}	
					}					
				}
				//USUARIO LOGADO
			}
			
		}
	}
		
	return 0;
}
