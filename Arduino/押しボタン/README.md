# <p align="center"> **押しボタン** </p> <p align="center"> **Oshibotan** </p>

Un énième jeu avec un nom accrocheur sans réel gameplay.

`"Un bouton à appuyer, un score qui grimpe et une limite à dépasser."`

<p align="center">

  <img src="https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fmedia3.giphy.com%2Fmedia%2FgH8aoZWs43yEJ4Wren%2Fgiphy.gif&f=1&nofb=1">

</p>

---
# **Principe**
Le but du jeu est d'appuyer sur un bouton poussoir pour faire monter un compteur de score le plus vite possible pendant un temps imparti. Le score actuel s'affiche sur l'afficheur 7 segments et le score à la fin de la partie ainsi que le meilleur score sont envoyés sur la liaison série à chaque fin de partie. Le son du buzzer indiquera la fin de la partie.

## **Etape 1** : Affichage du nombre d'appuis sur le bouton
* Programmer un compteur qui s'incrémente à chaque appui sur le bouton 1
* Afficher la valeur du compteur sur l'afficheur 7 segments

## **Etape 2** : Nombre d'appuis réinitialisés périodiquement
* Programmer un timer qui remet à zéro le compteur d'appui toutes les 10 secondes et stocke sa dernière valeur et sa valeur maximale

## **Etape 3** : Indication sonore du début et de la fin de partie
* Programmer une indication sonore du buzzer quand les 10 secondes sont écoulées

## **Etape 4** : Envoi du score actuel et du meilleur score sur le port série
* Envoyer sur le port série la valeur du compteur au bout des 10 secondes
* Envoyer sur le port série la valeur la plus haute atteinte par le compteur

## **Etape 5** : La petite touche personnelle
* Proposer des améliorations (départ contrôlé, temps réglable, ...)
  

---
# Ressources
* `oshibotan.ino` : sketch principal
* `vma209.h` : #define du mapping des broches du shield
* `aff7seg.h` : prototype des fonctions pour l'afficheur 7 segments
* `aff7seg.cpp` : description des fonctions pour l'afficheur 7 segments