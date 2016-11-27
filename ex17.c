/* ************************************************************************ *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *    Copyright (C) 2016 by Marina Collier de Albuquerque Melo              *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *    To contact the author, please write to:                               *
 *                                                                          *
 *    Marina Collier de Albuquerque Melo <marinacollieramelo@gmail.com      *
 *    Phone: 55 81 994923617                                                *
 *                                                                          *
 *    Fernando Angelim Aragão <bituco99@gmail.com>                          *
 *    phone: 55 81 997107784                                                *
 * ************************************************************************ *
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_lst                           // Definindo um tipo de variavel "string"
{                                               // 
    int c;                                     // Unico valor da lista, do tipo char
    struct st_lst *prox;                        // Ponteiro da lista, apontando para o proximo
}lista;     

void disp(lista *s);
void push(lista **cabeca, int x);
int pop(lista **cabeca);

int main(void)                                  
{                                                

    lista *l=NULL;
    char *pc, a, c, *str=NULL;
    int i=0;

    str = (char *) malloc(sizeof(char));

    printf("Digite a equacao\n");

    while((c=getchar())!='\n' && c!='\0')
    {
        str = (char *) realloc(str, strlen(str)+sizeof(char));
        *(str + i*sizeof(char)) = c;
        i++;
    }

    *(str + i * sizeof(char)) = '\0';

    pc = str;

    while(*pc!='\0')
    {
        switch (*pc)
        {
            case '+':
                printf("+\n%d\n",a=pop(&l)+pop(&l));
                push(&l, a);
                break;

            case '-':
                printf("-\n%d\n",a=pop(&l)-pop(&l));
                push(&l, a);
                break;

            case '*':
                printf("*\n%d\n",a=pop(&l)*pop(&l));
                push(&l, a);
                break;

            case '/':
                printf("/\n%d\n",a=pop(&l)/pop(&l));
                push(&l, a);
                break;

            default:
                push(&l, *pc-'0');
        }

        disp(l);
        pc++; 
    }                                           
    printf("\n");                               
    return 0;                                   
}            
void disp(lista *s)
{
    lista *p = s;
    while(p!=NULL)
    {
        printf("%d ",p->c);
        p=p->prox;
    }
    printf("\n");

}
void push(lista **cabeca, int x)
{
    lista *pl=*cabeca;
    lista *plant=NULL;
    
    while(pl!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }
    pl=malloc(sizeof(lista));
    pl->c=x;
    pl->prox=NULL;
    
    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;
}

int pop(lista **cabeca)
{
    lista *pl=*cabeca;
    lista *plant=NULL;
    int x;

    while(pl->prox!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }
    if(plant!=NULL)
        plant->prox=NULL;
    else
        *cabeca=NULL;
    
    x = pl->c;
    free(pl);
    
    return x;
}
