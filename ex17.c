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
    char c;                                     // Unico valor da lista, do tipo char
    struct st_lst *prox;                        // Ponteiro da lista, apontando para o proximo
}lista;     

void push(lista **cabeca, char x);
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
                printf("+\n%d\n",pop(&l)+pop(&l));
                break;

            case '-':
                printf("-\n%d\n",pop(&l)-pop(&l));
                break;

            case '*':
                printf("*\n%d\n",pop(&l)*pop(&l));
                break;

            case '/':
                printf("/\n%d\n",pop(&l)/pop(&l));
                break;

            default:
                push(&l, *pc);
        }

        pc++; 
    }                                           
    printf("\n");                               
    return 0;                                   
}            

void push(lista **cabeca, char x)
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
    char x;

    while(pl->prox!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }
    x = pl->c-'0';
    plant->prox=NULL;
    free(pl);
    return x;
}
