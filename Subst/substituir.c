#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int espacio(char *s, char *p, char *r) {
	
	int ls= strlen(s);
	int lp= strlen(p);
	int lr= strlen(r);
	int i=0;
	
	while(*s!=0 && strlen(s)>lp)
	{
		
		 if(strncmp(s,p,lp)==0){
			i++;
			s=s+lp;
					}
		else{
			s++;	}
	
	}
	if(lr>lp){
		return (lr-lp)*i +ls +1;}
	else{
		return 	ls -i*(lp-lr) +1;}

}

char *substituir(char *s, char *p, char *r) {
	int n=espacio(s,p,r);
	char *sub= (char *)malloc(n*sizeof(char));
	char *ssub=sub;
	int lp= strlen(p);
	int lr= strlen(r);

	while(*s!=0 && strlen(s)>lp)
		{
		
		 if(strncmp(s,p,lp)==0){
			strcat(sub,r);
			s=s+lp;
			ssub=ssub+lr;
					}
		else{
			*ssub=*s;
			s++;
			ssub++;
			}	
	
		}
	strcat(sub,s);
	printf(" |%s|", sub);
  	return sub;
}

int main() {
  if (espacio("hola mundo", "hello", "bonjour")!=11)
    printf("falla test 1\n");
  else if (espacio("hola mundo", "ola", "ello")!=12)
    printf("falla test 2\n");
  else if (espacio("elgatotemelperro", "el", "un")!=17)
    printf("falla test 3\n");
  else if (strcmp(substituir("hola mundo", "hello", "bonjour"),
             "hola mundo") != 0)
    printf("falla test 4\n");
  else if (strcmp(substituir("hola mundo", "ola", "ello"),
                  "hello mundo") != 0)
    printf("falla test 5\n");
  else if (strcmp(substituir("elgatotemelperro", "el", "un"),
                  "ungatotemunperro") != 0)
    printf("falla test 6\n");
  else
    printf("Todos los tests funcionan correctamente\n");
  return 0;
}

