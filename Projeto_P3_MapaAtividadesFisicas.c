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
	char typeOf[30];
	float duration;
	float caloriesLost;
	float caloriesPerHour;
};

struct Day{
	char date[10];
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
	
	int i,j;
	float somaCalories = 0;
	
	printf("================================================================================================\n\n");
		printf("Dias e Atividades: \n\n");
		
		for( i=0 ; i<7 ; i++){
			printf("------------------------------------------------------------------------\n");
			if(i == 0){
				
				if( user.days[i].caloriesTotal == 0){
					printf("Hoje, voce ainda nao cadastrou atividades fisicas !");
				}else{
					printf("\nHoje, na data [%s], voce praticou: ", user.days[i].date );
					
					for( j=0 ; j<3 ; j++){
						
						printf("\n\n - Tipo de Atividade: %s", user.days[i].activities[j].typeOf);
						printf("\n - Duracao: %.1f H", user.days[i].activities[j].duration);
						printf("\n - Calorias perdidas: %.2f Cal\n ", user.days[i].activities[j].caloriesLost);
						
					}
					
				}
				
			}else{
				
				if( user.days[i].caloriesTotal == 0){
					printf("Ha %d dia(as) atras, voce ainda nao cadastrou atividades fisicas !", i);
				}else{
					printf("\nHoje, na data [%s], voce praticou: ", user.days[i].date );
					
					for( j=0 ; j<3 ; j++){
						
						printf("\n\n - Tipo de Atividade: %s", user.days[i].activities[j].typeOf);
						printf("\n - Duracao: %.1f H", user.days[i].activities[j].duration);
						printf("\n - Calorias perdidas: %.2 Cal\n ", user.days[i].activities[j].caloriesLost);
						
					}
				}
				
			}
			printf("\n------------------------------------------------------------------------\n\n");
		}
		
		for( i=0 ; i<7 ; i++){
			somaCalories = somaCalories + user.days[i].caloriesTotal;
		}
		
		printf("Seu 'Gasto (ou Ganho) Calorico' durante os ultimos 7 dias: %.2f", somaCalories );
		printf("\nSua 'Peso Inicial': %.2f", user.initialWeight);
		printf("\nSua 'Sua Altura': %d", user.height);
			
		
		printf("\n\n(0) - Voltar para a pagina incial.\n");
		printf("(2) - Editar Dias e Atividades Fisicas");
		
	printf("\n\n================================================================================================\n");	
}

void editActivities(){
	printf("================================\n\n");
		printf("Pagina de Edicao: \n\n");
		printf("(0) - Editar atividades de hoje.\n");
		printf("(1) - Editar atividades de ontem.\n");
		printf("(2) - Editar atividades de 2 dia atras.\n");
		printf("(3) - Editar atividades de 3 dia atras.\n");
		printf("(4) - Editar atividades de 4 dia atras.\n");
		printf("(5) - Editar atividades de 5 dia atras.\n");
		printf("(6) - Editar atividades de 6 dia atras.\n");
		printf("(-1) - Voltar para a pagina inicial");
		
	printf("\n\n================================\n");
}

void editActivitiesFunc(int dayInd){
	
	int i;
	
	printf("================================\n\n");
		
		if(dayInd == 0){
			printf("Editar atividades de Hoje\n\n");
		}else if(dayInd == 1){
			printf("Editar atividades de Ontem\n\n");
		} else {
			printf("Editar atividades de %d dias atras\n\n", dayInd);
		}
		
		for( i=0 ; i<3 ; i++){
			printf("(%d) - Alterar Atividade %d (Tipo: %s)\n", i , i+1 , user.days[dayInd].activities[i].typeOf);
		}
		
	printf("\n================================\n");
}

void editActivitiesFuncReal(int temp , int dayInd ){
	int escolha;
	printf("================================\n\n");
		
		printf("(0) - Apagar todos os dados da atividade.\n");
		printf("(1) - Modificar dados da atividade.\n");
		
	printf("\n================================\n");
	printf("Digite sua escolha: ");
	scanf("%d", &escolha);
	system("cls");
	
	if(escolha == 0){
		user.days[dayInd].activities[temp].caloriesLost = 0;
		user.days[dayInd].activities[temp].duration = 0;
		user.days[dayInd].activities[temp].type = -1;
		user.days[dayInd].activities[temp].typeOf[30] = "\0";
		
		printf("================================\n\n");
		printf("Dados apagos com Sucesso.\n\n");
	}else if(escolha == 1){
		
		int newTemp = 0;
		
		while(newTemp != -1){
			printf("================================\n\n");
		
			printf("Tipo de Atividade: %s \nDuracao da Atividade: %.2f \nCalorias Perdidas na Atividade: %.2f", user.days[dayInd].activities[temp].typeOf , user.days[dayInd].activities[temp].duration , user.days[dayInd].activities[temp].caloriesLost);
			
			printf("\n\n(0) - Alterar Duracao.\n");
			printf("(1) - Alterar Tipo.\n");
			printf("(-1) - Salvar alteracao.\n");
			
			printf("\n================================\n");	
			printf("Digite sua escolha: ");
			scanf("%d", &newTemp);
			
			
			if(newTemp == 0){
				
				if(user.days[dayInd].activities[temp].type != NULL){
					printf("================================\n\n");
		
					printf("Digite a nova Duracao (em Horas): ");
					scanf("%f" , &user.days[dayInd].activities[temp].duration);
					
					user.days[dayInd].activities[temp].caloriesLost = (user.days[dayInd].activities[temp].caloriesPerHour)*(user.days[dayInd].activities[temp].duration);
				
				}else{
					system("cls");
					printf("================================\n\n");
		
					printf("Alterar a 'Duracao' adicione um 'Tipo'.\n\n");
				}
				
			}else if(newTemp == 1){
				system("cls");
				
				int tipo; 
				
				printf("================================\n\n");
				
				printf("(0) - CORRIDA\n");
				printf("(1) - CAMINHADA\n");
				printf("(2) - BICICLETA\n");
				printf("(3) - NATACAO\n");
				printf("(4) - MUSCULACAO\n");
				printf("(5) - DANCA\n");
				printf("(6) - Outros\n");
				
				printf("\n================================\n");	
				printf("Digite sua escolha: ");
				scanf("%d", &tipo);
				system("cls");
				
				user.days[dayInd].activities[temp].type = tipo;
				
				if(tipo == 0){
					user.days[dayInd].activities[temp].caloriesPerHour = 700;
					user.days[dayInd].activities[temp].typeOf[30] = "CORRIDA";
					user.days[dayInd].activities[temp].caloriesLost = (user.days[dayInd].activities[temp].caloriesPerHour)*(user.days[dayInd].activities[temp].duration);
				}else if(tipo == 1){
					user.days[dayInd].activities[temp].caloriesPerHour = 535;
					user.days[dayInd].activities[temp].typeOf[30] = "CAMINHADA";
					user.days[dayInd].activities[temp].caloriesLost = (user.days[dayInd].activities[temp].caloriesPerHour)*(user.days[dayInd].activities[temp].duration);
				}else if(tipo == 2){
					user.days[dayInd].activities[temp].caloriesPerHour = 800;
					user.days[dayInd].activities[temp].typeOf[30] = "BICICLETA";
					user.days[dayInd].activities[temp].caloriesLost = (user.days[dayInd].activities[temp].caloriesPerHour)*(user.days[dayInd].activities[temp].duration);
				}
				else if(tipo == 3){
					user.days[dayInd].activities[temp].caloriesPerHour = 700 ;
					user.days[dayInd].activities[temp].typeOf[30] = "NATACAO";
					user.days[dayInd].activities[temp].caloriesLost = (user.days[dayInd].activities[temp].caloriesPerHour)*(user.days[dayInd].activities[temp].duration);
				}
				else if(tipo == 4){
					user.days[dayInd].activities[temp].caloriesPerHour = 400;
					user.days[dayInd].activities[temp].typeOf[30] = "MUSCULACAO";
					user.days[dayInd].activities[temp].caloriesLost = (user.days[dayInd].activities[temp].caloriesPerHour)*(user.days[dayInd].activities[temp].duration);
				}
				else if(tipo == 5){
					user.days[dayInd].activities[temp].caloriesPerHour = 450 ;
					user.days[dayInd].activities[temp].typeOf[30] = "DANCA";
					user.days[dayInd].activities[temp].caloriesLost = (user.days[dayInd].activities[temp].caloriesPerHour)*(user.days[dayInd].activities[temp].duration);
				}
				else if(tipo == 6){
					
					printf("Digite o 'tipo de atividade': ");
					scanf("%s" , &user.days[dayInd].activities[temp].typeOf);
					user.days[dayInd].activities[temp].typeOf[30] = toupper(user.days[dayInd].activities[temp].typeOf);
					printf("Digite quantas 'calorias sao gastar por hora' (cal/h): ");
					scanf("%f" , &user.days[dayInd].activities[temp].caloriesPerHour);
					
					user.days[dayInd].activities[temp].caloriesLost = (user.days[dayInd].activities[temp].caloriesPerHour)*(user.days[dayInd].activities[temp].duration);
				}
				
			} 
			
			if(newTemp == -1){
				int j;
				user.days[dayInd].caloriesTotal = 0;
				
				for( j=0 ; j<3 ; j++){
					user.days[dayInd].caloriesTotal = user.days[dayInd].caloriesTotal + user.days[dayInd].activities[j].caloriesLost;
				}
				
			}	
			
		}		
		
		printf("================================\n\n");
		printf("Dados Modificados com Sucesso.\n\n");
	}
	
	
	
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
								
								if(stateLogged == 2){
									int dayIndex;
									editActivities();
									printf("Digite sua escolha: ");
									scanf("%d", &dayIndex);
									system("cls");
									
									if(dayIndex == -1){
										stateLogged = 0;
									}else{
										
										int temp;
										editActivitiesFunc(dayIndex);
										printf("Digite sua escolha: ");
										scanf("%d", &temp);
										system("cls");
										
										editActivitiesFuncReal(temp , dayIndex);
										// Ajustar essa parte Ajustar essa parte Ajustar essa parte Ajustar essa parte Ajustar essa parte 
										if(dayIndex == -1){
											stateLogged = 0;
										}
										// Ajustar essa parte Ajustar essa parte Ajustar essa parte Ajustar essa parte Ajustar essa parte 
									}
									
									system("cls");
								}
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
