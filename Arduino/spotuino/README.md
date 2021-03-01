# Spotuino : Lecteur de musique sur Arduino

**Spotuino** est un projet à dispostion des curieux et intéressés qui veulent consacrer un peu de leur temps libre à approfondir leurs compétences en Arduino. La cible du projet est l'Arduino Uno avec l'utilisation du shield VMA209. C'est un lecteur de musique sur buzzer contrôlable avec les boutons et le potentiomètre avec affichage dynamique sur l'afficheur sept segments.

Les fonctionnalités à implémenter sont pour l'instant :
* Musique jouée sur le buzzer
* Chenillard synchronisé avec le tempo
* Vitesse de lecture variable grâce au potentiomètre activable grâce à un bouton poussoir
* Lecture et arrêt de la musique avec un bouton poussoir
* Nom de la musique jouée et avancement affichés sur le port série
* Tempo affiché sur l'afficheur sept segments

Le projet est découpé en plusieurs étapes pour vous faciliter le développement du projet.

Je vous conseille fortement d'organiser votre projet en fichiers pour que votre projet reste clair et compréhensible. Un exemple d'organisation est le suivant

**Spotuino** :
* `logs.txt` ou `.md` : pour mettre vos notes (avancements, idées, problèmes)
* `spotuino.ino` : sketch principal du projet
* `spotuino.h` : déclaration des fonctions utilisées (prototypes)
* `spotuino.cpp` : définitions des fonctions utilisées
* `vma209.h` : #define utiles propres au shield vma209
* `pitches.h` : bibliothèque qui contient les fréquences des notes

# Etape 1 : Jouer une musique sur le buzzer

Le toute première étape est la programmation de la musique sur le buzzer. Il existe de nombreux exemples sur internet qui utilisent la bibliothèque `pitches.h` qui fait correspondre les fréquences des signaux carrés avec les notes de musique. Les plus braves choisiront de programmer une musique que l'on trouve pas en ligne en la traduisant en C.

Un point de départ peut être la création de deux tableaux : un tableau avec les notes de musiques et un tableau de rhythme (durée des notes). La musique se fera donc calculant pour chaque indice du tableau quelle note jouée et pendant combien de temps en fonction du tempo.

> **Aide**
> * Générer un signal carré sur une pin
>```C++
> tone(pin, frequency, duration);
> ```
> * Arrêter la génération d'un signal carrée sur une pin
>```C++
> noTone(pin); // ne fonctionnera pas sur le buzzer :)
> ```
> * Créer une attente d'une durée donnée
> ```C++
> delay(ms);
>```

# Etape 2 : Chenillard au tempo de la musique

Fort de votre expertise en chenillard cette étape devrait être assez simple. Elle consiste à faire avancer le chenillard au tempo de la musique que l'on note souvent BPM pour Beats Per Minute (les adeptes de trans ou autre dingueries savent de quoi il en retourne).

Prenons par exemple `Fuzz Universe` de Paul Gilbert dont le BPM moyen est de 129, le chenillard avancerait donc toutes les 1/129 secondes.

> **Aide**
> * Créer une attente d'une durée donnée
> ```C++
> delay(ms);
>```

# Etape 3 : Remplacer les appels bloquants (delay())

La fonction `delay()` bien que très pratique au premier abord est en fait assez contraignante puisqu'elle génère un appel bloquant. En d'autres termes, l'appel à cette fonction bloque votre Arduino à cette instruction nous empêchant alors de faire autre chose. Utiliser cette fonction revient alors à s'imposer la loi de boire ou conduire, sauf qu'en grand inconscients que nous sommes on va faire les deux en même temps grâce à la fonction `millis()`.

La fonction millis() renvoie le temps écoulé depuis l'exécution de votre programme. Si on stocke cette valeur dans une variable on pourra alors compter le temps écoulé entre deux appels de la fonction millis(). Enfin, avec quelques blocs if/else on peut donc créer une temporisation non bloquante.

Maintenant il ne vous reste plus qu'à appliquer cette modification partout !

> **Aide**
> * Récupérer le temps écoulé depuis l'exécution du programme en ms
> ```C++
> unsigned long time = millis();
>```
> * Récupérer le temps écoulé depuis l'exécution du programme en µs
> ```C++
> unsigned long time = micros();
>```

# Etape 4 : Tempo commandé par potentiomètre

Pour préparer votre session DJ à Ibiza il va vous falloir de quoi faire grimper les BPM en fin de soirée. On va donc permettre le changement du tempo grâce au potentiomètre présent sur la carte.

Rien de bien nouveau pour vous, il suffit de modifier la valeur de votre variable de tempo en se basant sur la lecture du potentiomètre. Le petit bonus serait de limiter la vitesse de rafraichissement de la valeur du potentiomètre avec un bloc if/millis() vu que la valeur de ce dernier fluctue beaucoup.

> **Aide**
> * Lire une valeur analogique depuis une broche ADC
> ```C++
> analogRead(pin);
>```
> * Modifier la plage de valeur d'une variable
> ```C
> map(value, fromLow, fromHigh, toLow, toHigh);
>```

# Etape 5 : Arrêt de la musique commandé par bouton

Puisque toute bonne chose a une fin, il va falloir un moyen pratique d'arrêter notre douce mélodie. Pour cela on va utiliser un bouton poussoir et même mieux que ça, on va bien l'utiliser.

Il existe une triste vérité derrière les boutons poussoirs qui est la présence d'un [effet de rebond](http://pila.fr/wordpress/?p=77) qu'internet saura bien vous expliquer et imager. Pour pallier ce problème il faudra réaliser un filtre anti-rebond en logiciel qui peut simplement se constituer d'un temps minimum entre chaque lecture du bouton poussoir de façon à attendre la fin des rebonds. Vous l'avez sûrement senti venir, ce sera encore un bloc if/millis() :)

Une bonne chose à faire serait également de faire qu'un appui sur le bouton arrête la musique et qu'un autre appui la remet. Ce comportement peut se faire avec une variable qui retient l'état du bouton.

> **Aide**
> * Le type de variable booléen
> ```C++
> bool ar = true;
> bool on = false;
>```
> * Inverser l'état d'un booléen
> ```C
> ar = !ar;
>```

# Etape 6 : Nom de la musique affiché sur le port série

Une étape facile pour booster le moral avant le gros morceau que va être l'afficheur 7 segments. Pour cette étape on va utiliser le port série pour afficher la musique jouée ainsi que son avancement (en secondes ou avancement de l'indice du tableau).

Pour ne pas saturer le moniteur il serait intéressant de trouver une solution qui n'utilise qu'une seule ligne du moniteur pendant toute la durée de la chanson.

> **Aide**
> * Initialiser une communication série (dans le setup)
> ```C++
> Serial.begin(baudrate);
>```
> * Envoyer sur le port série
> ```C
> Serial.print(val);
>```
> * Les caractères ASCII spéciaux
> ```C
> '\r' : retour au début de la ligne
> '\n' : va à la ligne suivante
>```

# Etape 7 : Afficher le tempo sur l'afficheur 7 segments

Fécilitations aux grands baroudeurs et baroudeuses qui ont survécus jusqu'ici. Au programme du plaisir jusqu'à plus soif avec l'afficheur 7 segments. 

À suivre ...