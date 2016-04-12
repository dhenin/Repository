#include <stdio.h>
#include <ctype.h>
#include "Pile.tda"

#define RIEN        -1
#define NB         256
#define OP         257
#define EOE        258


struct item 
{
   int type ;
   union 
   {
       char op  ;
       int  val ;
   } contenu ;
    
} ;

typedef struct item   ITEM ;
typedef struct item * Item ;


void Item_editer (Item i)
{
    if (OP == i->type ) printf ("%c", i->contenu) ; 
    else printf ("%d", i->contenu) ;
}

Item Item_copier (Item i)
{
    Item j ;

    j = (Item) malloc (sizeof (*i)) ;
    *j = *i ;
    return j ;
}

void Item_detruire (Item i)
{
    free (i) ;
}

pile (Item) ;
Itempile p ;

int ValLex ; 
int Symbole ;

Erreur (char * Message)
{
    fprintf (stderr, "%s\n", Message) ;
    exit (1) ;
}

int AnalLex ()
{
    int T ;

    while (1)
    {
    T = getchar() ;
    if (' ' == T || '\t' == T)
       ;     /* On saute les blancs */
    else if ('\n' == T || ';' == T)
    {
       return EOE ;
    }
    else if (isdigit(T))
    {
        ungetc (T, stdin) ;
        scanf  ("%d", &ValLex) ;
        return NB ;
    }
    else if (EOF == T)
        return EOF ;
    else
    {
        ValLex = RIEN ;
        return T ;
    }
    }
}

Analyse ()
{
    Symbole = AnalLex () ;
    while (EOF != Symbole)
    {
    Expr () ; 
    if (EOE == Symbole)
    {
        Itempile_afficher(p) ;
        Accepter (Symbole) ;
    }
    }
}


Expr ()
{
     int T ;

     Terme () ;
     while (1)
     switch (Symbole)
     {
         case '+' : case '-' :
         T = Symbole ;
         Accepter (Symbole) ;
         Terme () ;
         Emettre (T, RIEN) ;
         continue ;
         default :
         return ;
         }
}

Terme ()
{
    int T ;

    Facteur () ;

    while (1)
    switch (Symbole)
    {
        case '*' : case '/' :
         T = Symbole ;
         Accepter (Symbole) ;
         Facteur () ;
         Emettre (T, RIEN) ;
         continue ;
         default :
         return ;
    }
}

Facteur ()
{
    switch (Symbole)
    {
    case '(' :
        Accepter ('(') ; Expr () ; Accepter (')') ; break ;
    case NB : 
            Emettre (NB, ValLex) ; Accepter (NB) ; break ;
    case EOE :
               break ;
    default : 
        Erreur ("Syntaxe") ;
    }
}

Accepter (int Lex) 
{
     if (Symbole == Lex)
     Symbole = AnalLex () ;
     else Erreur ("Syntaxe") ;
}



Emettre (Lex, Val)
int Lex, Val ;
{
     ITEM x ; Item y ;

     switch (Lex)
     {
     case '+' : case '-' : case '*' : case '/' :
         /* printf ("%c\n", Lex) ; break ; */
             x.type = OP ;
         x.contenu = Lex ;
         y = Item_copier(&x) ;
         Itempile_empiler  (p, y) ;
         break ;

     case NB : 
         /* printf ("%d\n", Val) ; break ; */
             x.type = NB ;
         x.contenu = Val ;
         y = Item_copier(&x) ;
         Itempile_empiler  (p, y) ;
         break ;

     default :
         printf ("Lexeme %d, ValLex %d\n", Lex, Val) ; 
     }
}

main ()
{

    p = Itempile_creer(Item_copier, Item_detruire, Item_editer) ;

    Analyse() ;
    exit (0)  ;
}

