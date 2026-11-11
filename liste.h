#ifndef LISTE_H
#define LISTE_H
#include <stddef.h>
typedef struct Noeud { int valeur; struct Noeud *suivant; } Noeud;
typedef struct { Noeud *tete; size_t taille; } Liste;
void liste_init(Liste *l);
int liste_inserer_tete(Liste *l, int v);
int liste_inserer_queue(Liste *l, int v);
int liste_supprimer(Liste *l, int v);
int liste_contient(const Liste *l, int v);
void liste_afficher(const Liste *l);
void liste_detruire(Liste *l);
void liste_inverser(Liste *l);
int liste_milieu(const Liste *l, int *out);
#endif
