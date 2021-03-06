#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define tamAluno 1	// Constante para definir o tamanho do vetor "students". Quantidade de estudantes a serem cadastrados.
#define tamProf 1	// Constate que define o tamanho do vetor "teachers". Quantidade de professores a serem cadastrados.
#define tamGeral tamAluno + tamProf // Constante que define o tamanho do vetor "geral".

/* PROJETO SIMPLES DESENVOLVIDO EM C DURANTE FINALIZA??O DO M?DULO DE L?GICA DE PROGRAMA??O
DO CURSO T?CNICO DE DESENVOLVIMENTO DE SISTEMA. Desenvolvido pelo aluno Atila Bezerrra */

// OBS: A quantidade de pessoas a serem cadastrada podem ser alterada nas constantes. 

//Criando uma estrutura que cont?m dodos das caracter?sticas de uma pessoa.
typedef struct{
	char nome[30], sexo[15];
	int idade;
	float altura;
	int id;	// Ser? atribu?do a cada pessoa cadastrada para identifica??o. Id igual a zero ? atribuido aos alunos, j? o id igual 1 ? atribuido aos professores.
	char titulacao[15];	// Ser? usado para salvar no vetor geral a titula??o de cada professor e reutilizar para imprimir na busca.
}Pessoa;

//Criando uma estrutura que cont?m as dados de uma pessoa. al?m dos dados dos alunos.
typedef struct {
	Pessoa info;
	float nota1, nota2, media;
}Aluno;

//Criando estrutura que cont?m os dados de uma pessoa e a titula??o do professor.
typedef struct {
	Pessoa info;
	char titulacao[15];
}Professor;

Aluno students[tamAluno]; // Vetor para armazenar os cadastros de alunos.
Professor teachers[tamProf]; // Vetor para armazenar os cadastros de professores.
Pessoa geral[tamAluno + tamProf]; // Vetor que armazena alunos e professores, respectivamente, com dados de uma pessoa.

int i = 0; // Vari?vel global para usar como ?ndice nos la?os de repeti??es.
int verfA = 0, verfP = 0; // Vari?veis auxili?res para atribui??es na fun??o cadastroAluno() e cadastroProfessor(). Armazena 1 caso a fun??o designada for executada pelo usu?rio.

//Fun??o para limpar a sa?da.
void limparTela(){
	printf("Aguarde...");
	sleep(1);
	system("cls");	// Limpa a tela do terminal.
}

//Fun??o do menu que sera exibido na execu??o do programa.
int menuPrincipal(){

	int op; // Vari?vel que cont?m a op??o desejada pelo usu?rio.
	
	do{
		printf("---------- PROJETO: L?GICA DE PROGRAMA??O ----------\n\n");
		printf("1 - Cadastro de Alunos;\n2 - Cadastro de Professor;\n3 - Rela??o de Alunos;\n4 - Rela??o de Professores;\n5 - Situa??o Escolar dos Alunos;\n");
		printf("6 - Pesquisar;\n7 - Dados Amostrais;\n8 - Sair.\n\n");
		printf("Informe a sua op??o: ");
		scanf("%d", &op);
		if(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7 && op != 8){
			limparTela();
			printf("-----> ERRO! A Op??o digitada ? inv?lida! Favor digitar op??o novamente. <-----\n\n");
		} // Estrutura de condi??o que informa ao usu?rio um erro, caso tenha digitado algo que n?o corresponde as op??es oferecidas.
	}while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7 && op != 8); // Estrutra que repete o menu at? a op??o digitada pelo usu?rio seja v?lida.
	
	return op;	// Retornando a op??o desejada pelo usu?rio.
}	

//Submenu para a op??o de dados amostrais.
int menuDadosAmostrais(){
	
	limparTela();
	int esc;	// Vari?vel que cont?m a escolha desejada pelo usu?rio.
	do{
		printf("---------- DADOS AMOSTRAIS ----------\n\n");
		printf("1 - Pessoa(s) mais nova(s) e a(s) mais velha(s);\n2 - M?dia das alturas cadastradas;\n3 - Verificar maiores que a idade informada;\n");
		printf("4 - Voltar ao menu principal.\n\n");
		printf("Digite Op??o: ");
		scanf("%d", &esc);
		if(esc != 1 && esc != 2 && esc != 3 && esc != 4){
			limparTela();
			printf("-----> A Op??o digitada ? inv?lida! Favor digitar op??o novamente. <-----\n\n");
		}	// Estrutura de condi??o que informa ao usu?rio um erro caso tenha digitado algo que n?o corresponde as op??es oferecidas.
	}while(esc != 1 && esc != 2 && esc != 3 && esc != 4);	// Estrutra que repete at? a op??o digitada pelo usu?rio seja v?lida.
	
	if(esc == 4){
		limparTela();
	}	// Por quest?es est?ticas, caso o usu?rio digite a op??o de voltar menu anterior, a tela ser? limpa. Caso ao contr?rio, n?o ter? neccessidade.
	
	return esc;		// Retornando a escolha desejada pelo usu?rio.
}

//Submenu para a op??o de busca.
int menuBusca(){
	
	limparTela();
	int bsc;	// Vari?vel para armazenar a op??o de busca escolhida pelo usu?rios.
	
	do{
		printf("1 - Busca por sexo.\n");
		printf("2 - Busca por nome.\n");
		printf("3 - Voltar ao menu principal.\n\n");
		printf("Digite Op??o: ");
		scanf("%d", &bsc);
		if(bsc != 1 && bsc != 2 && bsc != 3){
			limparTela();
			printf("-----> A Op??o digitada ? inv?lida! Favor digitar op??o novamente. <-----\n\n");
		}	// Estrutura de condi??o que informa ao usu?rio um erro, caso tenha digitado algo que n?o corresponde as op??es oferecidas.
	}while (bsc != 1 && bsc != 2 && bsc != 3);	// Estrutra que repete at? a op??o digitada pelo usu?rio seja v?lida.
	
	if(bsc == 3){
		limparTela();
	}	// Por quest?es est?ticas, caso o usu?rio digite a op??o de voltar menu anterior, a tela ser? limpa. Caso ao contr?rio, n?o ter? neccessidade.
	
	return bsc;		// Retornando a op??o de busca desejada pelo usu?rio.
}

//Fun??o para realizar o cadastro de alunos.
void cadastroAluno(){
	
	limparTela();

	for (i = 0; i < tamAluno; i++){ 	// La?o de repeti??o para preencher o vetor students com seus dados. Casa posi??o "i" ? um estudante cadastrada no vetor "students".
		printf("---------- CADASTRO DE ALUNO ----------\n\n");
		printf("Digite o nome do %d? aluno: ", i + 1);
		fflush(stdin);					// A fun??o fflush() ? usado para limpar o buffer da mem?ria.
		gets(students[i].info.nome);	// A fun??o gets() ? usado para armazenar uma string em uma determinada vari?vel.
		printf("Digite a idade do %d? aluno: ", i + 1);
		scanf("%d", &students[i].info.idade);
		printf("Digite o sexo do %d? aluno: ", i + 1);
		fflush(stdin);
		gets(students[i].info.sexo);	
		printf("Digite a altura do %d? aluno: ", i + 1);
		scanf("%f", &students[i].info.altura);
		printf("Informe a 1? nota do %d? aluno: ", i + 1);
		scanf("%f", &students[i].nota1);
		printf("Informe a 2? nota do %d? aluno: ", i + 1);
		scanf("%f", &students[i].nota2);
		students[i].media = (students[i].nota1 + students[i].nota2)/2;
		limparTela();
		teachers[i].info.id = 0;	// Definindo ID igual a 0, para identific?-lo como aluno.
	}
	
	verfA = 1; // Armazena 1 para determinar que essa fun??o foi executada pelo usu?rio.
}

//Fun??o para realizar o cadastro de professoes.
void cadastroProfessor(){
	
	limparTela();
	
	for (i = 0; i < tamProf; i++) {		// La?o de repeti??o para preencher o vetor teachers e seus dados. Casa posi??o "i" ? um estudante cadastrada no vetor "students".
		printf("---------- CADASTRO DE PROFESSOR ----------\n\n");
		printf("Digite o nome do %d? professor: ", i + 1);
		fflush(stdin);					// fflush() ? usado para limpar o buffer da mem?ria.
		gets(teachers[i].info.nome);	// gets() ? usado para armazenar uma string em uma determinada vari?vel.
		printf("Digite a idade do %d? professor: ", i + 1);
		scanf("%d", &teachers[i].info.idade);
		printf("Digite o sexo do %d? professor: ", i + 1);
		fflush(stdin);
		gets(teachers[i].info.sexo);	
		printf("Digite a altura do %d? professor: ", i + 1);
		scanf("%f", &teachers[i].info.altura);
		printf("Digite a Titula??o do %d? professor: ", i + 1);
		fflush(stdin);
		gets(teachers[i].titulacao);
		limparTela();
		teachers[i].info.id = 1;
	}
	
	verfP = 1;	// Armazena 1 para determinar que essa fun??o foi executada.
}

//	Fun??o para armazenar todas as pessoas cadastradas no vetor "geral".
int preencherGeral(){
	
	int j = 0;
	
	int cont = 0;	// Contador de pessoas armazenadas no vetor "geral".
	
	if (verfA == 1){	// Verifica se a fun??o cadastroAluno() foi executada pelo usu?rio para depois armazenar no vetor "geral".
		for(i = 0; i < tamAluno; i++){
			strcpy(geral[i].nome, students[i].info.nome);	// A fun??o strcpy() da biblioteca "string.h" faz a copia de uma vari?vel string para outra vari?vel do mesmo tipo.
			geral[i].idade = students[i].info.idade;
			geral[i].altura = students[i].info.altura;
			strcpy(geral[i].sexo, students[i].info.sexo);
			geral[i].id = students[i].info.id;
			cont++;	// Cada incrementa??o determina que os dados de uma pessoa foi armazenado no vetor "geral".
		}	// La?o de repeti??o que, ao executar, recolhe as informa??es do vetor "students" e armazena no vetor "geral". O "i" determina em qual espa?o do vetor est? sendo armazenado, sendo incrementado ao fim de cada execu??o.
	}
	
	if(verfA == 0){		// Nessa condi??o, a fun??o cadastroAluo() n?o foi executada.
		if(verfP == 1){		// Se a fun??o cadastroProfessor() foi executada, nessa condi??o ela deve preencher o vetor "geral" pegando como partida, ou seja o ?ndice, o espa?o 0 do vetor.
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
	}else{	// Nessa condi??o a fun??o cadastroAluno() foi executada.
		if(verfP == 1){		// Nesse caso, verfA n?o ? igual a 0 e a fun??o cadastroAluno() foi executada. A estrutura de condi??o ir? testar se verfP ? igual a 1. Se for verdadeiro, o vetor "geral" ser? preenchido com os dados dos professores definindo como ?ndice inicial um espa?o ap?s o ?timo espa?o preenchido anteriormente.
			for(i = tamAluno; i < tamGeral; i++){
				strcpy(geral[i].nome, teachers[j].info.nome);
				geral[i].idade = teachers[j].info.idade;
				geral[i].altura = teachers[j].info.altura;
				strcpy(geral[i].sexo, teachers[j].info.sexo);
				geral[i].id = 1;
				strcpy(geral[i].titulacao, teachers[j].titulacao);
				j++;	// Ind?ce ser? usuado para o vetor "teachers" nesse la?o de repeti??o, garantido que pegue como espa?o incial o 0 e incrementando conforme necess?rio.
				cont++;
			}
		}
	}

	return cont;	// Retornando a vari?vel que contem o total de pessoas armazenadas no vetor "geral". Ser? utilizado nas fun??es posteriores.
}

//Fun??o para exibir na tela todos os alunos cadastrados.
void imprimirAluno(){
	if (verfA == 1){ 	// Condi??o para verificar se a fun??o cadastroAluno() foi executada, para exibi-la. Caso verfA seja igual 1, a fun??o foi executada.
		limparTela();
		printf("---------- RELA??O DE ALUNOS ----------\n\n");
		for(i = 0; i < tamAluno; i++){		// La?o de repeti??o que pega todos estudantes preenchido no vetor e imprimi. Casa posi??o "i" ? um estudante cadastrada no vetor "students".
			printf("Nome do %d? Aluno: %s\n", i + 1, students[i].info.nome);
			printf("Idade do %d? Aluno: %d\n", i + 1, students[i].info.idade);
			printf("Sexo do %d? Aluno: %s\n", i + 1, students[i].info.sexo);
			printf("Altura do %d? Aluno: %.2f\n", i + 1, students[i].info.altura);
			printf("-------------------------------------\n\n");
		}	
		system("pause");	// Pausa do sistema para leitura da impress?o, antes de retornar ao menu.
		limparTela();
	}else{		// Condi??o para verificar se a fun??o cadastroAluno() foi executada pelo usu?rio, caso ao contr?rio, n?o tem o que exibir.
		limparTela();
		printf("-----> ERRO! ? necess?rio realizar o cadastro de alunos! <-----\n\n");
	}
}

//Fun??o para exibir na tela todos os professores cadastrados.
void imprimirProfessor(){
		
	if(verfP == 1){		// Condi??o para verificar se a fun??o cadastroProfessor() foi executada para exibi-la. Caso verfA seja igual 1, a fun??o foi executada.
		limparTela();
		printf("---------- RELA??O DE PROFESSORES ----------\n\n");
		for(i = 0; i < tamProf; i++){		// La?o de repeti??o que pega todos professores preenchido no vetor e imprimi. Casa posi??o "i" ? um estudante cadastrada no vetor "students".
			printf("Nome do %d? Professor: %s\n", i + 1, teachers[i].info.nome);
			printf("Idade do %d? Professor: %d\n", i + 1, teachers[i].info.idade);
			printf("Sexo do %d? Professor: %s\n", i + 1, teachers[i].info.sexo);
			printf("Altura do %d? Professor: %.2f\n", i + 1, teachers[i].info.altura);
			printf("Titula??o do %d? Professor: %s\n", i + 1, teachers[i].titulacao);
			printf("-------------------------------------\n\n");
		}
		system("pause");	// Pausa do sistema para leitura da impress?o, antes de retornar ao menu.
		limparTela();
	}else{		// Condi??o para verificar se a fun??o cadastroProfessor() foi executada pelo usu?rio, caso ao contr?rio, n?o tem o que exibir.
		limparTela();
		printf("-----> ERRO! ? necess?rio realizar o cadastro de professores! <-----\n\n");
	}
}

//Fun??o para relacionar alunos em aprovados, reprovados e recupe??o.
void statusAlunos(){
	
	if(verfA == 1){		// // Condi??o para verificar se a fun??o cadastroAluno() foi executada, para exibir o status dos alunos. Caso verfA seja igual 1, a fun??o foi executada.
		limparTela();
		
		printf("---------- RELA??O DE ALUNOS ----------\n\n");
		
		for(i = 0; i < tamAluno; i++){	// Estrutura de repeti??o para rodar o vetor students.
			printf("Aluno: %s\n", students[i].info.nome);	// Nome do estudante na posi??o (i).
			printf("M?dia: %.2f\n", students[i].media);		// M?dia do estudante na posi??o (i).
			if(students[i].media >= 7){
				printf("Status: Aluno Aprovado!!!\n");
			}else if(students[i].media >= 5){
				printf("Status: Aluno em Recupera??o!!!\n");
			}else {
				printf("Status: Aluno Reprovado!!!\n");
			} // Estrutra de repeti??o que verifica a m?dia e retorna o status de aprova??o.
			printf("-------------------------------------\n\n");
		}
		
		system("pause");
		limparTela();
	}else{	// Condi??o para verificar se a fun??o cadastroAluno() foi executada pelo usu?rio, caso ao contr?rio, n?o tem o que exibir.
		limparTela();
		printf("-----> ERRO! ? necess?rio realizar o cadastro de alunos! <-----\n\n");
	}
}

//Fun??o para verificar quem ? a pessoa mais velha cadastrada, assim como a mais nova.
void verificarIdade(){

		limparTela();
		int cont = preencherGeral();	// Armazenando o retorno da fun??o que cont?m a quantidade de pessoas cadastradas no vetor "geral" para utilizar nos la?os de repeti??es.
		
		int maior = geral[0].idade, menor = geral[0].idade;	// Vari?veis auxiliares para armazenar a primeira idade do vetor "geral" e realizar futuras compara??es de maior e menor.
		
		printf("---------- DADOS AMOSTRAIS: Rela??o de Idade ----------\n\n");
		for(i = 0; i < cont; i++){
			if (geral[i].idade > maior){	// Estrutura de condi??o para verificar se a idade da posi??o "i" do vetor "geral" ? maior que a idade armazenada na vari?vel "maior".
				maior = geral[i].idade;	// Case a condi??o for validada, o valor da vari?vel maior ? modificada para a idade na posi??o "i".
			}	
		}	// Esse la?o de repeti??o ir? pecorrer o vetor "geral" e armazenar o maior valor atribuido a idade de cada pessoa.
		
		printf("Idade da(s) pessoa(s) mais velha(s) cadastrada(s): %d\n", maior);	// Imprimindo a maior idade armazenada.
		for(i = 0; i < cont; i++){
			if(maior == geral[i].idade){
				printf("Pessoa(s): %s\n", geral[i].nome);
			}	// Essa condi??o exibi somente as pessoas que possuem a idade igual a armazenada na vari?vel "maior".
		}
		
		for(i = 0; i < cont; i++){
			if (geral[i].idade < menor){	// Estrutura de condi??o para verificar se a idade da posi??o "i" do vetor "geral" ? menor que a idade armazenada na vari?vel "menor".
				menor = geral[i].idade;	// Case a condi??o for validada, o valor da vari?vel menor ? modificada para a idade na posi??o "i".
			}	
		}
		
		printf("\nIdade da(s) pessoa(s) mais nova(s) cadastrada(s): %d\n", menor);	// Imprimindo a menor idade armazenada.
		for(i = 0; i < cont; i++){
			if(menor == geral[i].idade){
				printf("Pessoas: %s\n", geral[i].nome);
			}	// Essa condi??o exibi somente as pessoas que possuem a idade igual a armazenada na vari?vel "menor".
		}
		printf("\n");
		system("pause");
		
}

//Fun??o para mostrar pessoas maiores que a idade informada.
int verfIdadeInform(){
	
	int inform; // Vari?vel para armazenar a idade informada pelo usu?rio.
	int cont = preencherGeral();	// Armazenando retorno da fun??o preencherGeral(), que ? a quantidade de pessoas armazenadas no vetor geral.
	
	limparTela();
	printf("---------- DADOS AMOSTRAIS: Pessoas Maiores Que A Idade Informada ----------\n\n");
	printf("Informe uma idade: ");
	scanf("%d", &inform);	// Solicitando ao usu?rio que informe uma idade para a verifica??o.
	
	printf("\n-------------------------------------\n");
	for(i = 0; i < cont; i++){
		if(geral[i].idade > inform){	// Estrutura de repeti??o que exibe as informa??es das pessoas que cont?m a idade maior do que a informada.
			printf("Nome da pessoa: %s\n", geral[i].nome);
			printf("Idade: %d\n", geral[i].idade);
			printf("Altura: %.2f\n", geral[i].altura);
			printf("Sexo: %s\n", geral[i].sexo);
			printf("-------------------------------------\n\n");
		}
	}
	system("pause");
}

//Fun??o para buscar genero dos cadastrados.
int buscaSexo(){
	
	char inform[15];	// Vari?vel que cont?m o sexo informado pelo usu?rio.
	int cont = preencherGeral();	// Armazenando o retorno da fun??o preencherGeral(), que ? a quantidade de pessoas armazenadas no vetor geral.
		
	limparTela();
	printf("---------- DADOS AMOSTRAIS: Pesquisa por Sexo ----------\n\n");
	printf("Informe um sexo: ");
	fflush(stdin);
	gets(inform); // Armazenando o sexo informado pelo usu?rio na vari?vel inform.
	
	printf("\n-------------------------------------\n");
	for(i = 0; i < cont; i++){
		if(strcasecmp(inform, geral[i].sexo) == 0){		// A fun??o strcasecmp() da biblioteca string.h pega duas vari?veis do tipo string e realiza a compara??o. Se for igual, retorna o valor 0.
			printf("Nome da pessoa: %s\n", geral[i].nome);
			printf("Idade: %d\n", geral[i].idade);
			printf("Altura: %.2f\n", geral[i].altura);
			printf("Sexo: %s\n", geral[i].sexo);
			if(geral[i].id == 1){
				printf("Professor(a)\n");
				printf("Titula??o: %s\n", geral[i].titulacao);
			}	// Estrutura de condi??o que exibe as informa??es caso o sexo informado seja igual ao sexo das pessoas armazenadas no vetor geral.
			printf("-------------------------------------\n");
		}	
	}
	
	system("pause");
}

//Fun??o para buscar nome de cadastrados.
int buscaNome() {
	
	char inform[15];
	int cont = preencherGeral();	// Armazenando o retorno da fun??o preencherGeral(), que ? a quantidade de pessoas armazenadas no vetor geral.
		
	limparTela();
	printf("---------- DADOS AMOSTRAIS: Pesquisa por Nome ----------\n\n");
	printf("Informe um nome: ");
	fflush(stdin);
	gets(inform);	// Armazenando o nome informado pelo usu?rio na vari?vel inform.
	
	printf("\n-------------------------------------\n");
	for(i = 0; i < cont; i++){
		if(strcasecmp(inform, geral[i].nome) == 0){	
			printf("Nome da pessoa: %s\n", geral[i].nome);
			printf("Idade: %d\n", geral[i].idade);
			printf("Altura: %.2f\n", geral[i].altura);
			printf("Sexo: %s\n", geral[i].sexo);
			if(geral[i].id == 1){
				printf("Professor(a)\n");
				printf("Titula??o: %s\n", geral[i].titulacao);
			}	// Estrutura de condi??o que pega exibe as informa??es caso o nome informado seja igual ao nome das pessoas armazeznadas no vetor geral.
			printf("-------------------------------------\n\n");
		}	
	}
	
	system("pause");
}

//Fun??o para informar m?dia de altura dos cadastrados.
int mediaAltura() {
	
	limparTela();
	float somaAlturaGeral = 0, mediaAlturaGeral;	// Vari?veis auxiliares para realizar o c?lculo de m?dia aritm?tica.
	int cont, contador = 0;
	
	cont = preencherGeral();	// Armazenado o retorno da fun??o preencherGeral(), que ? a quantidade de pessoas armazenadas no vetor geral.
	
	for(i = 0; i < cont; i++){
		somaAlturaGeral += geral[i].altura;	// Soma todas as alturas das pessoas armazenadas no vetor geral.
		contador++;		// Contabiliza quantas pessoas tem no vetor geral.
	}
	
	mediaAlturaGeral = somaAlturaGeral/contador;		// Realiza o c?lculo de m?dia, que ? a soma de todas alturas divido pela quantidade de pessoas.
	
	printf("---------- RELA??O DE PROFESSORES ----------\n\n");
	printf("M?dia de alturas cadastradas: %.2f\n", mediaAlturaGeral);
	system("pause");
}

//Fun??o principal.
int main() {
	setlocale(LC_ALL, "portuguese");	// Definido idioma da execu??o.
	int esc, op, bsc;
	
	do{
		op = menuPrincipal();	// Armazenando o retorno de menuPrincipal().
		switch(op){		// Escolhendo a vari?vel op, do tipo inteiro, e definido a a??o que ser? efetuada em casa op??o num?rica.
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
				if(verfA == 1 || verfP == 1){	// Essa op??o s? ser? dispon?vel se tiver o cadastrado de estudantes e professores forem realizados.
					do{
						bsc = menuBusca();	// Armazenando o retorno de menuBusca(), que ? a op??o escolhida pelo usu?rio no menu.
						switch(bsc){
							case 1:
								buscaSexo();
								break;
							case 2:
								buscaNome();
								break;
						}
					}while(bsc != 3);	// La?o de repti??o para executar o menu caso bsc for diferente de 3.
				}else {
					limparTela();
					printf("-----> ERRO! ? necess?rio realizar o cadastro de pessoas! <-----\n\n");
				}
				
				break;
			case 7:
				if(verfA == 1 || verfP == 1){	// Essa op??o s? ser? dispon?vel se tiver o cadastrado de estudantes e professores forem realizados.
					do{
						esc = menuDadosAmostrais();	// Armazenando o retorno de menuDadosAmostrais(), que ? a op??o escolhida pelo usu?rio no menu.
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
					}while(esc != 4);	// La?o de repti??o para executar o menu caso esc for diferente de 4.
				} else {
					limparTela();
					printf("-----> ERRO! ? necess?rio realizar o cadastro de pessoas! <-----\n\n");
				}
				break;
			case 8:
				printf("\nFinalizando...");
				sleep(1);
				break;
		}
	}while(op != 8);	// La?o de repti??o para executar o menu caso op for diferente de 8.
}

