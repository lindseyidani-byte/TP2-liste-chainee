#include <assert.h>
#include <stdio.h>
#include "liste.h"
int main(void) {
    Liste l; int x; liste_init(&l);
    assert(l.taille == 0); assert(liste_contient(&l, 5) == 0); assert(liste_supprimer(&l, 5) == -1); assert(liste_milieu(&l, &x) == -1);
    printf("test_liste_vide : OK\n");
    liste_init(&l); liste_inserer_tete(&l, 42); assert(l.taille == 1); assert(liste_milieu(&l, &x) == 0 && x == 42); liste_inverser(&l); liste_supprimer(&l, 42); liste_detruire(&l);
    printf("test_un_seul_element : OK\n");
    liste_init(&l); liste_inserer_tete(&l, 5); liste_inserer_tete(&l, 3); liste_inserer_tete(&l, 8); liste_inserer_queue(&l, 10);
    assert(liste_supprimer(&l, 99) == -1); assert(liste_supprimer(&l, 3) == 0); assert(liste_milieu(&l, &x) == 0 && x == 5); liste_inverser(&l); liste_detruire(&l);
    printf("test_insertions_et_suppression : OK\n");
    liste_init(&l); liste_inserer_tete(&l, 5); liste_inserer_tete(&l, 3); liste_inserer_tete(&l, 8);
    printf("Liste : "); liste_afficher(&l); liste_inverser(&l); printf("Apres inversion : "); liste_afficher(&l);
    if (liste_milieu(&l, &x) == 0) printf("Milieu : %d\n", x); liste_detruire(&l);
    printf("Tous les tests sont passes.\n"); return 0;
}
