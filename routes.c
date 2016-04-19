#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	char url[]="routes.dat";
	char c;
	FILE *arq;
	int maior = 0;
	int count = 0;
	int i;
	int maiores[9];
	for(i=0;i<9;i++){
		maiores[i] = 0;
	}
	int indice = 0;
	
	arq = fopen(url, "r");
	if(arq == NULL){
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	}else{
	    while( (c=fgetc(arq))!= EOF ){
			if (c == '\n' || c == ',') {
				if (count > maiores[indice]) {
					maiores[indice] = count;
					//printf("maior: %i\n",maiores[indice]);
				}
				count = 0;
				if(c == '\n'){
					indice = 0;
				}
				if(c == ','){
					indice++;
				}
			} else {
				count++;
			}
		}
	}
	printf("indice 0 :%i\n",maiores[0]);
	printf("indice 1 :%i\n",maiores[1]);
	printf("indice 2 :%i\n",maiores[2]);
	printf("indice 3 :%i\n",maiores[3]);
	printf("indice 4 :%i\n",maiores[4]);
	printf("indice 5 :%i\n",maiores[5]);
	printf("indice 6 :%i\n",maiores[6]);
	printf("indice 7 :%i\n",maiores[7]);
	printf("indice 8 :%i\n",maiores[8]);
	
	fclose(arq);
	
	int diferenca;
	indice = 0;
	
	arq = fopen(url, "r");
	if(arq == NULL){
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	}else{
	    while( (c=fgetc(arq))!= EOF ){
			if (c == '\n' || c == ',') {
				if (count < maiores[indice]) {
					diferenca = maiores[indice] - count;
					for(i=0;i<diferenca;i++){
						//printf(" ");
					}
				}
				count=0;
				if(c == '\n'){
					indice = 0;
					//printf("%c",c);
				}
				if(c == ','){
					indice++;
					//printf("%c",c);
				}
			} else {
				//printf("%c",c);
				count++;
			}
		}
	}
	
	
	return 0;
	
}
