# TP compteur

Dans ce TP, nous allons réaliser un compteur/décompteur synchrone sur 4 bits avec reset asynchrone et signal d'activation. 

# Description VHDL

Le schéma en bloc du module est le suivant :

* **clk** : horloge qui cadence l'incrément ou décrément du compteur
* **rst** : reset qui remet à sortie la sortie du compteur indépendemment de l'état de l'horloge
    - si 1 : remise à zéro de la sortie
    - si 0 : rien
* **en** : activation (enable) du compteur/décompteur
    - si 1 : le compteur/décompteur compte
    - si 0 : le compteur/décompteur ne fait rien (garde la même valeur)
* **inc** : choix de l'incrément ou décrément du compteur
    - si 1 : le compteur compte de 0 à 15
    - si 0 : le compteur compte de 15 à 0
* **s** : sortie du compteur

- [ ] Le nom du module et du fichier est : **compteur_4b**
- [ ] Le code est indenté
- [ ] Le module compile sans erreurs

> Aide & rappel :
> * utiliser le type de signal **unsigned** pour les additions/soustractions
> * bien indenter son code (tabulation avec la touche __tab__):
>   <pre><code>process(...)
>	begin
>	|	if ... then
>	|	|	if ... then
>	|	|	|
>	|	|	else
>   |   |   |
>	|	|	end if;
>	|	end if;
>	end process; 
>   </code></pre>


# Simulation

Créer un script.do qui simule tous les cas possibles et vérifier la sortie.


- [ ] Le compteur ne fonctionne que si le signal d'activation (enable) est à l'état haut
- [ ] Le compteur s'incrémente/décrémente uniquement aux front montants de l'horloge
- [ ] Le compteur revient à 0 si le reset est à 1
- [ ] Le compteur s'incrémente si inc est à '1'
- [ ] Le compteur se décrémente si inc est à '0'
- [ ] La sortie varie toujours entre 0 et 15

# Implémentation

Le fichier **test_carte.vhd** utilise le compteur que vous venez de décrire pour générer la commande du transcodeur 7 segments que vous avez décrit la semaine précédente. Ainsi, la sortie de votre compteur allant de 0 à 15 sera affichée sur les afficheurs de votre carte.

A l'aide de Quartus synthésier et implémenter le module **test_carte.vhd** avec les entrées et sorties connectées de la façon suivante :
* **clk**           : BTN0
* **rst**           : SW7
* **en**            : SW1
* **inc**           : SW0
* **aff7seg(6)**    : AFF7SEG_a
* **aff7seg(5)**    : AFF7SEG_b
* **aff7seg(4)**    : AFF7SEG_c
* **aff7seg(3)**    : AFF7SEG_d
* **aff7seg(2)**    : AFF7SEG_e
* **aff7seg(1)**    : AFF7SEG_f
* **aff7seg(0)**    : AFF7SEG_g

- [ ] L'appui sur un bouton change l'état du compteur si le reset est à 0 et l'activation (enable) est à 1
- [ ] Le module est conforme au cahier des charges



