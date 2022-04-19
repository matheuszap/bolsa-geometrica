#include <stdio.h>
#include <rpc/rpc.h>

// Interface gerada pelo RPCGen a partir da IDL (hw.x) especificada
#include "hw.h"

// O client 1 "configura" o servidor de acordo com o arquivo servidor.in
int setServer(CLIENT *loc_cl, char *host) {
	int   *reti = NULL;

	// Lendo arquivo stdin
	char descarte[256]; // leituras p/ descarte
	int nc=0;           // número de clientes
	int np=0;           // número de pecas
	int nest = 0;       // número de esteira
	int nprat = 0;      // número de prateleiras
	char peca;
	char est;
	char prat;

	int nClientes = 0;
	char pecasPorCliente[20];
	int qtdPorCliente[20];


	// Linha 1 do arquivo
	if (!fscanf(stdin, "%s %s %s", descarte, descarte, descarte)) {
						printf ("ERRO\n");
						return 1;
				}
	// Linha 2 do arquivo
	if (!fscanf(stdin, "%s %s %i", descarte, descarte, &nc)) {
						printf ("ERRO\n");
						return 1;
				}

	// Set nclientes no servidor
	reti = sclientes_1(&nc, loc_cl);
	if (reti == NULL) {
			clnt_perror(loc_cl,host);
			exit(1);
	}

	// Linha 3 arquivo
	if (!fscanf(stdin, "%s %s %i", descarte, descarte, &np)) {
						printf ("ERRO\n");
						return 1;
				}

	// Linha 4 arquivo
	if (!fscanf(stdin, "%s %s", descarte, descarte)) {
					 printf ("ERRO\n");
					 return 1;
				}
	for (int i=0; i < np; i++) {
		 if (!fscanf(stdin, "%c %c", &descarte[0], &peca)) {
							printf ("ERRO\n");
							return 1;
					 }
		 // Set peca no servidor
		 reti = specas_1(&peca, loc_cl);
		 if (reti == NULL) {
				 clnt_perror(loc_cl,host);
				 exit(1);
		 }
	}

	//linha 5 arquivo
	if (!fscanf(stdin, "%s %s %i", descarte, descarte, &nest)) {
						printf ("ERRO\n");
						return 1;
				}

	//linha 6 arquivo
	if (!fscanf(stdin, "%s %s", descarte, descarte)) {
					 printf ("ERRO\n");
					 return 1;
				}
	for (int i=0; i < nest; i++) {
		 if (!fscanf(stdin, "%c %c", &descarte[0], &est)) {
							printf ("ERRO\n");
							return 1;
					 }
		 // Set est no servidor
		  reti = sesteiras_1(&est, loc_cl);
		  if (reti == NULL) {
		 		 clnt_perror(loc_cl,host);
		 		 exit(1);
		  }
	}

	//linha 7 arquivo
	if (!fscanf(stdin, "%s %s %i", descarte, descarte, &nprat)) {
						printf ("ERRO\n");
						return 1;
				}

	//linha 8 arquivo
	if (!fscanf(stdin, "%s %s", descarte, descarte)) {
					 printf ("ERRO\n");
					 return 1;
				}
	for (int i=0; i < nprat; i++) {
		 if (!fscanf(stdin, "%c %c", &descarte[0], &prat)) {
							printf ("ERRO\n");
							return 1;
					 }
		// Set prateleira no servidor
		  reti = sprateleiras_1(&prat, loc_cl);
		  if (reti == NULL) {
		 		 clnt_perror(loc_cl,host);
		 		 exit(1);
		  }
	}

	//CLIENTE

	//linha 10 arquivo
	if (!fscanf(stdin, "%s %s %s", descarte, descarte, descarte)) {
						printf ("ERRO\n");
						return 1;
				}
				
	//linha 11 arquivo
	if (!fscanf(stdin, "%s %s", descarte, descarte)) {
					 printf ("ERRO\n");
					 return 1;
				}
	if (!fscanf(stdin, "%c", pecasPorCliente[nClientes])) {
					 printf ("ERRO\n");
					 return 1;
				}

	//linha 12 arquivo
	if (!fscanf(stdin, "%s %s", descarte, descarte)) {
					 printf ("ERRO\n");
					 return 1;
				}
	if (!fscanf(stdin, "%c", qtdPorCliente[nClientes])) {
					 printf ("ERRO\n");
					 return 1;
				}

	nClientes++;

	//linha 13 arquivo
	if (!fscanf(stdin, "%s %s", descarte, descarte)) {
					 printf ("ERRO\n");
					 return 1;
				}
	if (!fscanf(stdin, "%c", pecasPorCliente[nClientes])) {
					 printf ("ERRO\n");
					 return 1;
				}

	//linha 14 arquivo
	if (!fscanf(stdin, "%s %s", descarte, descarte)) {
					 printf ("ERRO\n");
					 return 1;
				}
	if (!fscanf(stdin, "%c", qtdPorCliente[nClientes])) {
					 printf ("ERRO\n");
					 return 1;
				}

	nClientes++;

	return 0;
}

int main (int argc, char *argv[]) {
	// Estrutura RPC de comunicação
	CLIENT *cl;

	// Verificação dos parâmetros oriundos da console
	if (argc != 3) {
		printf("ERRO: ./client <hostname> <nClient>\n");
		exit(1);
	}

	// Conexão com servidor RPCargv[1]
	cl = clnt_create(argv[1], PROG, VERS, "tcp");
	if (cl == NULL) {
		clnt_pcreateerror(argv[1]);
		exit(1);
	}

	// O Cliente 1 deve configurar o servidor de acordo com o arquivo de entrada (somente o Cliente 1)

	if (atoi(argv[2]) == 1) {
		setServer(cl,argv[1]);
	}

	// ...
	// continuar o código do problema.
	// TODO


	printf ("##  Cliente %d  ##\n",atoi(argv[2]));
	printf ("Status: atendido\n");
	printf ("pCli: B\n");
	printf ("###########\n");

	endclient_1(NULL, cl);
	// if (ret == NULL) {
	// 		clnt_perror(cl,argv[1]);
	// 		exit(1);
	// }

  svc_exit();
	return 0;
}
