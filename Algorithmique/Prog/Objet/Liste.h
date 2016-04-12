#define LISTE_H
#include <stdio.h>
#include <stdlib.h>

#define nom(a,b) a##b 

typedef struct cell
{
    void        * objet ;
    struct cell * suiv  ;
} * cellule ;

typedef struct tete
{
    cellule prem, vue, der, s ;
} * liste ;

extern void * lier_liste () ; 
struct fonctions
{
    liste  (*creer)      ()                         ;
    void   (*copier)     (void *)                   ;
    void   (*detruire)   (liste, void (*) (void*))  ;
    int    (*nulle)      (liste)                    ;
    void   (*premier)    (liste)                    ;
    void   (*dernier)    (liste)                    ;
    void   (*suivant)    (liste)                    ;
    int    (*fin)        (liste)                    ;
    void * (*lire)       (liste)                    ;
    void   (*insereravant) (liste, void *)          ;
    void   (*insererapres) (liste, void *)          ;
    void   (*remplacer)  (liste, void *, void (*) (void*)) ;
    void   (*oter)       (liste, void (*) ())       ;
    void   (*fixer)      (liste)                    ;
    int    (*retablir)   (liste)                    ;
    void   (*afficher)   (liste, void (*) ())       ;
} Liste ;
