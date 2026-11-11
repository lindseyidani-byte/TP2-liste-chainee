#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
void liste_init(Liste *l) { l->tete = NULL; l->taille = 0; }
int liste_inserer_tete(Liste *l, int v) { Noeud *n = malloc(sizeof *n); if (!n) return -1; n->valeur = v; n->suivant = l->tete; l->tete = n; l->taille++; return 0; }
int liste_inserer_queue(Liste *l, int v) { Noeud *n = malloc(sizeof *n); Noeud *c; if (!n) return -1; n->valeur = v; n->suivant = NULL; if (!l->tete) l->tete = n; else { c = l->tete; while (c->suivant) c = c->suivant; c->suivant = n; } l->taille++; return 0; }
int liste_supprimer(Liste *l, int v) { Noeud *c = l->tete; Noeud *p = NULL; while (c && c->valeur != v) { p = c; c = c->suivant; } if (!c) return -1; if (!p) l->tete = c->suivant; else p->suivant = c->suivant; free(c); l->taille--; return 0; }
int liste_contient(const Liste *l, int v) { Noeud *c = l->tete; while (c) { if (c->valeur == v) return 1; c = c->suivant; } return 0; }
void liste_afficher(const Liste *l) { Noeud *c = l->tete; printf("[ "); while (c) { printf("%d ", c->valeur); c = c->suivant; } printf("]\n"); }
void liste_detruire(Liste *l) { Noeud *c = l->tete; while (c) { Noeud *s = c->suivant; free(c); c = s; } l->tete = NULL; l->taille = 0; }
void liste_inverser(Liste *l) { Noeud *p = NULL; Noeud *c = l->tete; while (c) { Noeud *s = c->suivant; c->suivant = p; p = c; c = s; } l->tete = p; }
int liste_milieu(const Liste *l, int *out) { Noeud *lent = l->tete; Noeud *rap = l->tete; if (!l->tete) return -1; while (rap && rap->suivant) { rap = rap->suivant->suivant; lent = lent->suivant; } *out = lent->valeur; return 0; }
