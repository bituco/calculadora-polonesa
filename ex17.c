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

typedef struct st_lst                           // Definindo um tipo de variavel "string"
{                                               // 
    char c;                                     // Unico valor da lista, do tipo char
    struct st_lst *prox;                        // Ponteiro da lista, apontando para o proximo
}lista;     

void push(lista **cabeca, char x);
int pop(lista **cabeca);

int main(void)                                  
{                                                
    string **f = malloc(sizeof(string)),        
           *p = *f,                             
           *pa = *f;                            
    char *x="34+",                   
         *pc = x;                               

    printf("Digite a equacao\n");
    while(*pc!='\0')
    { 
        switch (*pc)
        {
            case '+':
                break;

            case '-':
                break;

            case '*':
                break;

            case '/':
                break;

            default
                push(*pc);
        }

    pc++; 
    }                                           
    printf("\n");                               
    return 0;                                   
}            

void push(char *pc)
{
    p = malloc(sizeof(string));             // p passa a apontar para uma nova regiao da memoria com o novo elemento da lista
    p->c = *pc;                             // Esse novo elemento vai ter como valor o valor atual do ponteiro pc
    p->prox = NULL;                         // 
    if(pa != NULL)                          // Se a lista nao estiver vazia,
        pa->prox = p;                       // 
    else                                    // Caso contrario,
        *f = p;                             // 
}
