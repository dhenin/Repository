#define ARBREBIN_H
typedef enum {racine, pere, gauche, droite} direction ;
typedef void * arbrebin ;
extern struct
{
    arbrebin (*creer)     ()                                    ;
    void     (*detruire)  (arbrebin, void (*) (void *))         ;
    int      (*existe)    (arbrebin, direction)                 ;
    void *   (*lire)      (arbrebin)                            ;
    int      (*aller)     (arbrebin, direction)                 ;
    void     (*ajouter)   (arbrebin, direction, void *)         ;
    int      (*oter)      (arbrebin, void (*) (void *))         ;
    void     (*remplacer) (arbrebin, void *, void (*) (void *)) ;
    void     (*fixer)     (arbrebin, direction)                 ;
    int      (*retablir)  (arbrebin)                            ;
    void     (*afficher)  (arbrebin, void (*) (void *))         ;
    void     (*deplacer)  (arbrebin, direction)                 ;
    void     greffer      (arbrebin, arbrebin, direction)       ;
    arbrebin tailler      (arbrebin, direction)                 ;
} Arbrebin ;
extern lier_arbrebin () ;
