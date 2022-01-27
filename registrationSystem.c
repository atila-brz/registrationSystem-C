#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define tamAluno 1	// Constante para definir o tamanho do vetor "students". Quantidade de estudantes a serem cadastrados.
#define tamProf 1	// Constate que define o tamanho do vetor "teachers". Quantidade de professores a serem cadastrados.
#define tamGeral tamAluno + tamProf // Constante que define o tamanho do vetor "geral".

/* PROJETO SIMPLES DESENVOLVIDO EM C DURANTE FINALIZAÇÃO DO MÓDULO DE LÓGICA DE PROGRAMAÇÃO
DO CURSO TÉCNICO DE DESENVOLVIMENTO DE SISTEMA. Desenvolvido pelo aluno Atila Bezerrra */

// OBS: A quantidade de pessoas a serem cadastrada podem ser alterada nas constantes. 

//Criando uma estrutura que contém dodos das características de uma pessoa.
typedef struct{
	char nome[30], sexo[15];
	int idade;
	float altura;
	int id;	// Será atribuído a cada pessoa cadastrada para identificação. Id igual a zero é atribuido aos alunos, já o id igual 1 é atribuido aos professores.
	char titulacao[15];	// Será usado para salvar no vetor geral a titulação de cada professor e reutilizar para imprimir na busca.
}Pessoa;

//Criando uma estrutura que contém as dados de uma pessoa. além dos dados dos alunos.
typedef struct {
	Pessoa info;
	float nota1, nota2, media;
}Aluno;

//Criando estrutura que contém os dados de uma pessoa e a titulação do professor.
typedef struct {
	Pessoa info;
	char titulacao[15];
}Professor;

Aluno students[tamAluno]; // Vetor para armazenar os cadastros de alunos.
Professor teachers[tamProf]; // Vetor para armazenar os cadastros de professores.
Pessoa geral[tamAluno + tamProf]; // Vetor que armazena alunos e professores, respectivamente, com dados de uma pessoa.

int i = 0; // Variável global para usar como índice nos laços de repetições.
int verfA = 0, verfP = 0; // Variáveis auxiliáres para atribuições na função cadastroAluno() e cadastroProfessor(). Armazena 1 caso a função designada for executada pelo usuário.

//Função para limpar a saída.
void limparTela(){
	printf("Aguarde...");
	sleep(1);
	system("cls");	// Limpa a tela do terminal.
}

//Função do menu que sera exibido na execução do programa.
int menuPrincipal(){

	int op; // Variável que contém a opção desejada pelo usuário.
	
	do{
		printf("---------- PROJETO: LÓGICA DE PROGRAMAÇÃO ----------\n\n");
		printf("1 - Cadastro de Alunos;\n2 - Cadastro de Professor;\n3 - Relação de Alunos;\n4 - Relação de Professores;\n5 - Situação Escolar dos Alunos;\n");
		printf("6 - Pesquisar;\n7 - Dados Amostrais;\n8 - Sair.\n\n");
		printf("Informe a sua opção: ");
		scanf("%d", &op);
		if(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7 && op != 8){
			limparTela();
			printf("-----> ERRO! A Opção digitada é inválida! Favor digitar opção novamente. <-----\n\n");
		} // Estrutura de condição que informa ao usuário um erro, caso tenha digitado algo que não corresponde as opções oferecidas.
	}while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7 && op != 8); // Estrutra que repete o menu até a opção digitada pelo usuário seja válida.
	
	return op;	// Retornando a opção desejada pelo usuário.
}	

//Submenu para a opção de dados amostrais.
int menuDadosAmostrais(){
	
	limparTela();
	int esc;	// Variável que contém a escolha desejada pelo usuário.
	do{
		printf("---------- DADOS AMOSTRAIS ----------\n\n");
		printf("1 - Pessoa(s) mais nova(s) e a(s) mais velha(s);\n2 - Média das alturas cadastradas;\n3 - Verificar maiores que a idade informada;\n");
		printf("4 - Voltar ao menu principal.\n\n");
		printf("Digite Opção: ");
		scanf("%d", &esc);
		if(esc != 1 && esc != 2 && esc != 3 && esc != 4){
			limparTela();
			printf("-----> A Opção digitada é inválida! Favor digitar opção novamente. <-----\n\n");
		}	// Estrutura de condição que informa ao usuário um erro caso tenha digitado algo que não corresponde as opções oferecidas.
	}while(esc != 1 && esc != 2 && esc != 3 && esc != 4);	// Estrutra que repete até a opção digitada pelo usuário seja válida.
	
	if(esc == 4){
		limparTela();
	}	// Por questões estéticas, caso o usuário digite a opção de voltar menu anterior, a tela será limpa. Caso ao contrário, não terá neccessidade.
	
	return esc;		// Retornando a escolha desejada pelo usuário.
}

//Submenu para a opção de busca.
int menuBusca(){
	
	limparTela();
	int bsc;	// Variável para armazenar a opção de busca escolhida pelo usuários.
	
	do{
		printf("1 - Busca por sexo.\n");
		printf("2 - Busca por nome.\n");
		printf("3 - Voltar ao menu principal.\n\n");
		printf("Digite Opção: ");
		scanf("%d", &bsc);
		if(bsc != 1 && bsc != 2 && bsc != 3){
			limparTela();
			printf("-----> A Opção digitada é inválida! Favor digitar opção novamente. <-----\n\n");
		}	// Estrutura de condição que informa ao usuário um erro, caso tenha digitado algo que não corresponde as opções oferecidas.
	}while (bsc != 1 && bsc != 2 && bsc != 3);	// Estrutra que repete até a opção digitada pelo usuário seja válida.
	
	if(bsc == 3){
		limparTela();
	}	// Por questões estéticas, caso o usuário digite a opção de voltar menu anterior, a tela será limpa. Caso ao contrário, não terá neccessidade.
	
	return bsc;		// Retornando a opção de busca desejada pelo usuário.
}

//Função para realizar o cadastro de alunos.
void cadastroAluno(){
	
	limparTela();

	for (i = 0; i < tamAluno; i++){ 	// Laço de repetição para preencher o vetor students com seus dados. Casa posição "i" é um estudante cadastrada no vetor "students".
		printf("---------- CADASTRO DE ALUNO ----------\n\n");
		printf("Digite o nome do %d° aluno: ", i + 1);
		fflush(stdin);					// A função fflush() é usado para limpar o buffer da memória.
		gets(students[i].info.nome);	// A função gets() é usado para armazenar uma string em uma determinada variável.
		printf("Digite a idade do %d° aluno: ", i + 1);
		scanf("%d", &students[i].info.idade);
		printf("Digite o sexo do %d° aluno: ", i + 1);
		fflush(stdin);
		gets(students[i].info.sexo);	
		printf("Digite a altura do %d° aluno: ", i + 1);
		scanf("%f", &students[i].info.altura);
		printf("Informe a 1° nota do %d° aluno: ", i + 1);
		scanf("%f", &students[i].nota1);
		printf("Informe a 2° nota do %d° aluno: ", i + 1);
		scanf("%f", &students[i].nota2);
		students[i].media = (students[i].nota1 + students[i].nota2)/2;
		limparTela();
		teachers[i].info.id = 0;	// Definindo ID igual a 0, para identificá-lo como aluno.
	}
	
	verfA = 1; // Armazena 1 para determinar que essa função foi executada pelo usuário.
}

//Função para realizar o cadastro de professoes.
void cadastroProfessor(){
	
	limparTela();
	
	for (i = 0; i < tamProf; i++) {		// Laço de repetição para preencher o vetor teachers e seus dados. Casa posição "i" é um estudante cadastrada no vetor "students".
		printf("---------- CADASTRO DE PROFESSOR ----------\n\n");
		printf("Digite o nome do %d° professor: ", i + 1);
		fflush(stdin);					// fflush() é usado para limpar o buffer da memória.
		gets(teachers[i].info.nome);	// gets() é usado para armazenar uma string em uma determinada variável.
		printf("Digite a idade do %d° professor: ", i + 1);
		scanf("%d", &teachers[i].info.idade);
		printf("Digite o sexo do %d° professor: ", i + 1);
		fflush(stdin);
		gets(teachers[i].info.sexo);	
		printf("Digite a altura do %d° professor: ", i + 1);
		scanf("%f", &teachers[i].info.altura);
		printf("Digite a Titulação do %d° professor: ", i + 1);
		fflush(stdin);
		gets(teachers[i].titulacao);
		limparTela();
		teachers[i].info.id = 1;
	}
	
	verfP = 1;	// Armazena 1 para determinar que essa função foi executada.
}

//	Função para armazenar todas as pessoas cadastradas no vetor "geral".
int preencherGeral(){
	
	int j = 0;
	
	int cont = 0;	// Contador de pessoas armazenadas no vetor "geral".
	
	if (verfA == 1){	// Verifica se a função cadastroAluno() foi executada pelo usuário para depois armazenar no vetor "geral".
		for(i = 0; i < tamAluno; i++){
			strcpy(geral[i].nome, students[i].info.nome);	// A função strcpy() da biblioteca "string.h" faz a copia de uma variável string para outra variável do mesmo tipo.
			geral[i].idade = students[i].info.idade;
			geral[i].altura = students[i].info.altura;
			strcpy(geral[i].sexo, students[i].info.sexo);
			geral[i].id = students[i].info.id;
			cont++;	// Cada incrementação determina que os dados de uma pessoa foi armazenado no vetor "geral".
		}	// Laço de repetição que, ao executar, recolhe as informações do vetor "students" e armazena no vetor "geral". O "i" determina em qual espaço do vetor está sendo armazenado, sendo incrementado ao fim de cada execução.
	}
	
	if(verfA == 0){		// Nessa condição, a função cadastroAluo() não foi executada.
		if(verfP == 1){		// Se a função cadastroProfessor() foi executada, nessa condição ela deve preencher o vetor "geral" pegando como partida, ou seja o índice, o espaço 0 do vetor.
			for(i = 0; i < tamProf; i++){
				strcpy(geral[i].nome, teachers[i].info.nome);
				geral[i].idade = teachers[i].info.idade;
				geral[i].altura = teachers[i].info.altura;
				strcpy(geral[i].sexo, teachers[i].info.sexo);
				geral[i].id = 1;
				strcpy(geral[i].titulacao, teachers[i].titulacao);
				cont++;
			}
		}
	}else{	// Nessa condição a função cadastroAluno() foi executada.
		if(verfP == 1){		// Nesse caso, verfA não é igual a 0 e a função cadastroAluno() foi executada. A estrutura de condição irá testar se verfP é igual a 1. Se for verdadeiro, o vetor "geral" será preenchido com os dados dos professores definindo como índice inicial um espaço após o útimo espaço preenchido anteriormente.
			for(i = tamAluno; i < tamGeral; i++){
				strcpy(geral[i].nome, teachers[j].info.nome);
				geral[i].idade = teachers[j].info.idade;
				geral[i].altura = teachers[j].info.altura;
				strcpy(geral[i].sexo, teachers[j].info.sexo);
				geral[i].id = 1;
				strcpy(geral[i].titulacao, teachers[j].titulacao);
				j++;	// Indíce será usuado para o vetor "teachers" nesse laço de repetição, garantido que pegue como espaço incial o 0 e incrementando conforme necessário.
				cont++;
			}
		}
	}

	return cont;	// Retornando a variável que contem o total de pessoas armazenadas no vetor "geral". Será utilizado nas funções posteriores.
}

//Função para exibir na tela todos os alunos cadastrados.
void imprimirAluno(){
	if (verfA == 1){ 	// Condição para verificar se a função cadastroAluno() foi executada, para exibi-la. Caso verfA seja igual 1, a função foi executada.
		limparTela();
		printf("---------- RELAÇÃO DE ALUNOS ----------\n\n");
		for(i = 0; i < tamAluno; i++){		// Laço de repetição que pega todos estudantes preenchido no vetor e imprimi. Casa posição "i" é um estudante cadastrada no vetor "students".
			printf("Nome do %d° Aluno: %s\n", i + 1, students[i].info.nome);
			printf("Idade do %d° Aluno: %d\n", i + 1, students[i].info.idade);
			printf("Sexo do %d° Aluno: %s\n", i + 1, students[i].info.sexo);
			printf("Altura do %d° Aluno: %.2f\n", i + 1, students[i].info.altura);
			printf("-------------------------------------\n\n");
		}	
		system("pause");	// Pausa do sistema para leitura da impressão, antes de retornar ao menu.
		limparTela();
	}else{		// Condição para verificar se a função cadastroAluno() foi executada pelo usuário, caso ao contrário, não tem o que exibir.
		limparTela();
		printf("-----> ERRO! É necessário realizar o cadastro de alunos! <-----\n\n");
	}
}

//Função para exibir na tela todos os professores cadastrados.
void imprimirProfessor(){
		
	if(verfP == 1){		// Condição para verificar se a função cadastroProfessor() foi executada para exibi-la. Caso verfA seja igual 1, a função foi executada.
		limparTela();
		printf("---------- RELAÇÃO DE PROFESSORES ----------\n\n");
		for(i = 0; i < tamProf; i++){		// Laço de repetição que pega todos professores preenchido no vetor e imprimi. Casa posição "i" é um estudante cadastrada no vetor "students".
			printf("Nome do %d° Professor: %s\n", i + 1, teachers[i].info.nome);
			printf("Idade do %d° Professor: %d\n", i + 1, teachers[i].info.idade);
			printf("Sexo do %d° Professor: %s\n", i + 1, teachers[i].info.sexo);
			printf("Altura do %d° Professor: %.2f\n", i + 1, teachers[i].info.altura);
			printf("Titulação do %d° Professor: %s\n", i + 1, teachers[i].titulacao);
			printf("-------------------------------------\n\n");
		}
		system("pause");	// Pausa do sistema para leitura da impressão, antes de retornar ao menu.
		limparTela();
	}else{		// Condição para verificar se a função cadastroProfessor() foi executada pelo usuário, caso ao contrário, não tem o que exibir.
		limparTela();
		printf("-----> ERRO! É necessário realizar o cadastro de professores! <-----\n\n");
	}
}

//Função para relacionar alunos em aprovados, reprovados e recupeção.
void statusAlunos(){
	
	if(verfA == 1){		// // Condição para verificar se a função cadastroAluno() foi executada, para exibir o status dos alunos. Caso verfA seja igual 1, a função foi executada.
		limparTela();
		
		printf("---------- RELAÇÃO DE ALUNOS ----------\n\n");
		
		for(i = 0; i < tamAluno; i++){	// Estrutura de repetição para rodar o vetor students.
			printf("Aluno: %s\n", students[i].info.nome);	// Nome do estudante na posição (i).
			printf("Média: %.2f\n", students[i].media);		// Média do estudante na posição (i).
			if(students[i].media >= 7){
				printf("Status: Aluno Aprovado!!!\n");
			}else if(students[i].media >= 5){
				printf("Status: Aluno em Recuperação!!!\n");
			}else {
				printf("Status: Aluno Reprovado!!!\n");
			} // Estrutra de repetição que verifica a média e retorna o status de aprovação.
			printf("-------------------------------------\n\n");
		}
		
		system("pause");
		limparTela();
	}else{	// Condição para verificar se a função cadastroAluno() foi executada pelo usuário, caso ao contrário, não tem o que exibir.
		limparTela();
		printf("-----> ERRO! É necessário realizar o cadastro de alunos! <-----\n\n");
	}
}

//Função para verificar quem é a pessoa mais velha cadastrada, assim como a mais nova.
void verificarIdade(){

		limparTela();
		int cont = preencherGeral();	// Armazenando o retorno da função que contém a quantidade de pessoas cadastradas no vetor "geral" para utilizar nos laços de repetições.
		
		int maior = geral[0].idade, menor = geral[0].idade;	// Variáveis auxiliares para armazenar a primeira idade do vetor "geral" e realizar futuras comparações de maior e menor.
		
		printf("---------- DADOS AMOSTRAIS: Relação de Idade ----------\n\n");
		for(i = 0; i < cont; i++){
			if (geral[i].idade > maior){	// Estrutura de condição para verificar se a idade da posição "i" do vetor "geral" é maior que a idade armazenada na variável "maior".
				maior = geral[i].idade;	// Case a condição for validada, o valor da variável maior é modificada para a idade na posição "i".
			}	
		}	// Esse laço de repetição irá pecorrer o vetor "geral" e armazenar o maior valor atribuido a idade de cada pessoa.
		
		printf("Idade da(s) pessoa(s) mais velha(s) cadastrada(s): %d\n", maior);	// Imprimindo a maior idade armazenada.
		for(i = 0; i < cont; i++){
			if(maior == geral[i].idade){
				printf("Pessoa(s): %s\n", geral[i].nome);
			}	// Essa condição exibi somente as pessoas que possuem a idade igual a armazenada na variável "maior".
		}
		
		for(i = 0; i < cont; i++){
			if (geral[i].idade < menor){	// Estrutura de condição para verificar se a idade da posição "i" do vetor "geral" é menor que a idade armazenada na variável "menor".
				menor = geral[i].idade;	// Case a condição for validada, o valor da variável menor é modificada para a idade na posição "i".
			}	
		}
		
		printf("\nIdade da(s) pessoa(s) mais nova(s) cadastrada(s): %d\n", menor);	// Imprimindo a menor idade armazenada.
		for(i = 0; i < cont; i++){
			if(menor == geral[i].idade){
				printf("Pessoas: %s\n", geral[i].nome);
			}	// Essa condição exibi somente as pessoas que possuem a idade igual a armazenada na variável "menor".
		}
		printf("\n");
		system("pause");
		
}

//Função para mostrar pessoas maiores que a idade informada.
int verfIdadeInform(){
	
	int inform; // Variável para armazenar a idade informada pelo usuário.
	int cont = preencherGeral();	// Armazenando retorno da função preencherGeral(), que é a quantidade de pessoas armazenadas no vetor geral.
	
	limparTela();
	printf("---------- DADOS AMOSTRAIS: Pessoas Maiores Que A Idade Informada ----------\n\n");
	printf("Informe uma idade: ");
	scanf("%d", &inform);	// Solicitando ao usuário que informe uma idade para a verificação.
	
	printf("\n-------------------------------------\n");
	for(i = 0; i < cont; i++){
		if(geral[i].idade > inform){	// Estrutura de repetição que exibe as informações das pessoas que contém a idade maior do que a informada.
			printf("Nome da pessoa: %s\n", geral[i].nome);
			printf("Idade: %d\n", geral[i].idade);
			printf("Altura: %.2f\n", geral[i].altura);
			printf("Sexo: %s\n", geral[i].sexo);
			printf("-------------------------------------\n\n");
		}
	}
	system("pause");
}

//Função para buscar genero dos cadastrados.
int buscaSexo(){
	
	char inform[15];	// Variável que contém o sexo informado pelo usuário.
	int cont = preencherGeral();	// Armazenando o retorno da função preencherGeral(), que é a quantidade de pessoas armazenadas no vetor geral.
		
	limparTela();
	printf("---------- DADOS AMOSTRAIS: Pesquisa por Sexo ----------\n\n");
	printf("Informe um sexo: ");
	fflush(stdin);
	gets(inform); // Armazenando o sexo informado pelo usuário na variável inform.
	
	printf("\n-------------------------------------\n");
	for(i = 0; i < cont; i++){
		if(strcasecmp(inform, geral[i].sexo) == 0){		// A função strcasecmp() da biblioteca string.h pega duas variáveis do tipo string e realiza a comparação. Se for igual, retorna o valor 0.
			printf("Nome da pessoa: %s\n", geral[i].nome);
			printf("Idade: %d\n", geral[i].idade);
			printf("Altura: %.2f\n", geral[i].altura);
			printf("Sexo: %s\n", geral[i].sexo);
			if(geral[i].id == 1){
				printf("Professor(a)\n");
				printf("Titulação: %s\n", geral[i].titulacao);
			}	// Estrutura de condição que exibe as informações caso o sexo informado seja igual ao sexo das pessoas armazenadas no vetor geral.
			printf("-------------------------------------\n");
		}	
	}
	
	system("pause");
}

//Função para buscar nome de cadastrados.
int buscaNome() {
	
	char inform[15];
	int cont = preencherGeral();	// Armazenando o retorno da função preencherGeral(), que é a quantidade de pessoas armazenadas no vetor geral.
		
	limparTela();
	printf("---------- DADOS AMOSTRAIS: Pesquisa por Nome ----------\n\n");
	printf("Informe um nome: ");
	fflush(stdin);
	gets(inform);	// Armazenando o nome informado pelo usuário na variável inform.
	
	printf("\n-------------------------------------\n");
	for(i = 0; i < cont; i++){
		if(strcasecmp(inform, geral[i].nome) == 0){	
			printf("Nome da pessoa: %s\n", geral[i].nome);
			printf("Idade: %d\n", geral[i].idade);
			printf("Altura: %.2f\n", geral[i].altura);
			printf("Sexo: %s\n", geral[i].sexo);
			if(geral[i].id == 1){
				printf("Professor(a)\n");
				printf("Titulação: %s\n", geral[i].titulacao);
			}	// Estrutura de condição que pega exibe as informações caso o nome informado seja igual ao nome das pessoas armazeznadas no vetor geral.
			printf("-------------------------------------\n\n");
		}	
	}
	
	system("pause");
}

//Função para informar média de altura dos cadastrados.
int mediaAltura() {
	
	limparTela();
	float somaAlturaGeral = 0, mediaAlturaGeral;	// Variáveis auxiliares para realizar o cálculo de média aritmética.
	int cont, contador = 0;
	
	cont = preencherGeral();	// Armazenado o retorno da função preencherGeral(), que é a quantidade de pessoas armazenadas no vetor geral.
	
	for(i = 0; i < cont; i++){
		somaAlturaGeral += geral[i].altura;	// Soma todas as alturas das pessoas armazenadas no vetor geral.
		contador++;		// Contabiliza quantas pessoas tem no vetor geral.
	}
	
	mediaAlturaGeral = somaAlturaGeral/contador;		// Realiza o cálculo de média, que é a soma de todas alturas divido pela quantidade de pessoas.
	
	printf("---------- RELAÇÃO DE PROFESSORES ----------\n\n");
	printf("Média de alturas cadastradas: %.2f\n", mediaAlturaGeral);
	system("pause");
}

//Função principal.
int main() {
	setlocale(LC_ALL, "portuguese");	// Definido idioma da execução.
	int esc, op, bsc;
	
	do{
		op = menuPrincipal();	// Armazenando o retorno de menuPrincipal().
		switch(op){		// Escolhendo a variável op, do tipo inteiro, e definido a ação que será efetuada em casa opção numérica.
			case 1:
				cadastroAluno();
				break;
			case 2:
				cadastroProfessor();
				break;
			case 3:
				imprimirAluno();
				break;
			case 4:
				imprimirProfessor();
				break;
			case 5:
				statusAlunos();
				break;
			case 6:
				if(verfA == 1 || verfP == 1){	// Essa opção só será disponível se tiver o cadastrado de estudantes e professores forem realizados.
					do{
						bsc = menuBusca();	// Armazenando o retorno de menuBusca(), que é a opção escolhida pelo usuário no menu.
						switch(bsc){
							case 1:
								buscaSexo();
								break;
							case 2:
								buscaNome();
								break;
						}
					}while(bsc != 3);	// Laço de reptição para executar o menu caso bsc for diferente de 3.
				}else {
					limparTela();
					printf("-----> ERRO! É necessário realizar o cadastro de pessoas! <-----\n\n");
				}
				
				break;
			case 7:
				if(verfA == 1 || verfP == 1){	// Essa opção só será disponível se tiver o cadastrado de estudantes e professores forem realizados.
					do{
						esc = menuDadosAmostrais();	// Armazenando o retorno de menuDadosAmostrais(), que é a opção escolhida pelo usuário no menu.
						switch(esc){
							case 1:
								verificarIdade();
								break;
							case 2:
								mediaAltura();
								break;
							case 3:
								verfIdadeInform();
								break;
							case 4:
								break;
						}
					}while(esc != 4);	// Laço de reptição para executar o menu caso esc for diferente de 4.
				} else {
					limparTela();
					printf("-----> ERRO! É necessário realizar o cadastro de pessoas! <-----\n\n");
				}
				break;
			case 8:
				printf("\nFinalizando...");
				sleep(1);
				break;
		}
	}while(op != 8);	// Laço de reptição para executar o menu caso op for diferente de 8.
}

