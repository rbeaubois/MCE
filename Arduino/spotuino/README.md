# Spotuino : Lecteur de musique sur Arduino

**Spotuino** est un projet à dispostion des curieux et intéressés qui veulent consacrer un peu de leur temps libre à approfondir leurs compétences en Arduino. La cible du projet est l'Arduino Uno avec l'utilisation du shield VMA209. C'est un lecteur de musique sur buzzer contrôlable avec les boutons et le potentiomètre avec affichage dynamique sur l'afficheur sept segments.

Les fonctionnalités à implémenter sont pour l'instant :
* Musique jouée sur le buzzer
* Chenillard synchronisé avec le tempo
* Vitesse de lecture variable grâce au potentiomètre activable grâce à un bouton poussoir
* Lecture et arrêt de la musique avec un bouton poussoir
* Nom de la musique jouée et avancement affichés sur le port série
* Tempo affiché sur l'afficheur sept segments

Le projet est découpé en plusieurs étapes pour vous faciliter le développement.

Je vous conseille fortement d'organiser votre projet en fichiers pour que votre projet reste clair et compréhensible. Je vous donne un exemple d'organisation et le squelette des fichiers qui vont avec

**Spotuino** :
* `logs.txt` ou `.md` : pour mettre vos notes (avancements, idées, problèmes)
* `spotuino.ino` : sketch principal du projet
* `spotuino.h` : déclaration des fonctions utilisées (prototypes)
* `spotuino.cpp` : définitions des fonctions utilisées
* `vma209.h` : #define utiles propres au shield vma209
* `pitches.h` : bibliothèque qui contient les fréquences des notes

Maintenant que vous savez tout, y a plus qu'à !
<p align="center">

  <img src="https://media.giphy.com/media/zvy1r6BEdGKtT7m5m6/giphy.gif#center">

</p>

# Etape 1 : Jouer une musique sur le buzzer

Le toute première étape est la programmation de la musique sur le buzzer. Il existe de nombreux exemples sur internet qui utilisent la bibliothèque `pitches.h` qui fait correspondre les fréquences des signaux carrés avec les notes de musique. Les plus braves choisiront de programmer une musique que l'on trouve pas en ligne en la traduisant en C.

Un point de départ peut être la création de deux tableaux : un tableau avec les notes de musiques et un tableau de rhythme (durée des notes). La musique se fera donc calculant pour chaque indice du tableau quelle note jouée et pendant combien de temps en fonction du tempo.

> **Aide**
> * Générer un signal carré sur une pin : [tone()](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/)
>```C++
> tone(pin, frequency, duration);
> ```
> * Arrêter la génération d'un signal carrée sur une pin : [noTone()](https://www.arduino.cc/reference/en/language/functions/advanced-io/notone/)
>```C++
> noTone(pin); // ne fonctionnera pas sur le buzzer, il faudra faire votre propre fonction :)
> ```
> * Créer une attente d'une durée donnée : [delay()](https://www.arduino.cc/reference/en/language/functions/time/delay/)
> ```C++
> delay(ms);
>```

# Etape 2 : Chenillard au tempo de la musique

Fort de votre expertise en chenillard cette étape devrait être assez simple. Elle consiste à faire avancer le chenillard au tempo de la musique que l'on note souvent BPM pour Beats Per Minute (les adeptes de trans ou autre dingueries savent de quoi il en retourne).

Prenons par exemple `Fuzz Universe` de Paul Gilbert dont le BPM moyen est de 129, le chenillard avancerait donc toutes les 1/129 minute.

> **Aide**
> * Créer une attente d'une durée donnée : [delay()](https://www.arduino.cc/reference/en/language/functions/time/delay/)
> ```C++
> delay(ms);
>```

# Etape 3 : Remplacer les appels bloquants (delay())

La fonction `delay()` bien que très pratique au premier abord est en fait assez contraignante puisqu'elle génère un appel bloquant. En d'autres termes, l'appel à cette fonction bloque votre Arduino à cette instruction nous empêchant alors de faire autre chose. Utiliser cette fonction revient alors à s'imposer la loi de boire ou conduire, sauf qu'en grand inconscients que nous sommes on va faire les deux en même temps grâce à la fonction `millis()`.

La fonction millis() renvoie le temps écoulé depuis l'exécution de votre programme. Si on stocke cette valeur dans une variable on pourra alors compter le temps écoulé entre deux appels de la fonction millis(). Enfin, avec quelques blocs if/else on peut donc créer une temporisation non bloquante.

Maintenant il ne vous reste plus qu'à appliquer cette modification partout !

> **Aide**
> * Récupérer le temps écoulé depuis l'exécution du programme en ms : [millis()](https://www.arduino.cc/reference/en/language/functions/time/millis/)
> ```C++
> unsigned long time = millis();
>```
> * Récupérer le temps écoulé depuis l'exécution du programme en µs : [micros()](https://www.arduino.cc/reference/en/language/functions/time/micros/)
> ```C++
> unsigned long time = micros();
>```
> * Spécificateur utile pour les variables des fonctions
> ```C++
> static
>```
> * Un exemple d'utilisation
> ```C++
> unsigned long it_time, t_last_action1, t_last_action2;  // Compteurs de temps
> unsigned long t_action1 = 100;  // Période d'exécution de l'action 1  
> unsigned long t_action2 = 500;  // Période d'exécution de l'action 2
> 
> void loop(){
>   it_time = millis(); // Temps écoulé jusqu'à cette itération
>   
>   if((it_time-t_last_action1) > t_action1){
>     t_last_action1 = it_time; // Rafraichissement du compteur
>     action1() // Exécution de l'action 1
>   }
> 
>   if((it_time-t_last_action2) > t_action2){
>     t_last_action2 = it_time; // Rafraichissement du compteur
>     action2() // Exécution de l'action 1
>   }
> }
> // Trouverez-vous la limitation de cette façon de faire et comment y remédier ? :)
> ```

# Etape 4 : Tempo commandé par potentiomètre

Pour préparer votre session DJ à Ibiza il va vous falloir de quoi faire grimper les BPM en fin de soirée. On va donc permettre le changement du tempo grâce au potentiomètre présent sur la carte.

Rien de bien nouveau pour vous, il suffit de modifier la valeur de votre variable de tempo en se basant sur la lecture du potentiomètre. Le petit bonus serait de limiter la vitesse de rafraichissement de la valeur du potentiomètre avec un bloc if/millis() vu que la valeur de ce dernier fluctue beaucoup.

> **Aide**
> * Lire une valeur analogique depuis une broche ADC : [analogRead()](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/)
> ```C++
> int val = analogRead(pin);
>```
> * Modifier la plage de valeur d'une variable : [map()](https://www.arduino.cc/reference/en/language/functions/math/map/)
> ```C
> int new_val = map(value, fromLow, fromHigh, toLow, toHigh); // Le type de retour va dépendre des valeurs que vous mappez
>```

# Etape 5 : Arrêt de la musique commandé par bouton

Puisque toute bonne chose a une fin, il va falloir un moyen pratique d'arrêter notre douce mélodie. Pour cela on va utiliser un bouton poussoir et même mieux que ça, on va bien l'utiliser.

Il existe une triste vérité derrière les boutons poussoirs qui est la présence d'un [effet de rebond](http://pila.fr/wordpress/?p=77) qu'internet saura bien vous expliquer et imager. Pour pallier ce problème il faudra réaliser un filtre anti-rebond en logiciel qui peut simplement se constituer d'un temps minimum entre chaque lecture du bouton poussoir de façon à attendre la fin des rebonds. Vous l'avez sûrement senti venir, ce sera encore un bloc if/millis() :)

Une bonne chose à faire serait également de faire qu'un appui sur le bouton arrête la musique et qu'un autre appui la remet. Ce comportement peut se faire avec une variable qui retient l'état du bouton.

> **Aide**
> * Le type de variable booléen : [bool](https://www.arduino.cc/reference/en/language/variables/data-types/bool/)
> ```C++
> bool ar = true;
> bool on = false;
>```
> * Inverser l'état d'un booléen
> ```C
> ar = !ar;
>```

# Etape 6 : Activation ou non de la vitesse variable

Tant que l'on est avec les boutons autant ajouter un autre bouton pour sélectionner ou non le tempo variable de la musique. On va dire qu'un appui permet de changer la vitesse avec le potentiomètre et qu'un rappui la désactive, c'est simple, basique !

# Etape 7 : Nom de la musique affiché sur le port série

Une étape facile pour booster le moral avant le gros morceau que va être l'afficheur 7 segments. Pour cette étape on va utiliser le port série pour afficher la musique jouée ainsi que son avancement (en secondes ou avancement de l'indice du tableau).

Pour ne pas saturer le moniteur il serait intéressant de trouver une solution qui n'utilise qu'une seule ligne du moniteur pendant toute la durée de la chanson.

> **Aide**
> * Initialiser une communication série (dans le setup) :  [Serial.begin()](https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/)
> ```C++
> Serial.begin(baudrate);
>```
> * Envoyer sur le port série : [Serial.print()](https://www.arduino.cc/reference/en/language/functions/communication/serial/print/)
> ```C
> Serial.print(val);
>```
> * Les caractères [ASCII](https://fr.wikibooks.org/wiki/Les_ASCII_de_0_%C3%A0_127/La_table_ASCII) spéciaux
> ```C
> '\r' : retour au début de la ligne
> '\n' : va à la ligne suivante
>```

# Etape 8 : Afficher le tempo sur l'afficheur 7 segments

Tout d'abord félicitations aux grands baroudeurs et baroudeuses qui ont survécus jusqu'ici. On va maintenant s'attaquer à l'afficheur 7 segments (en commençant avec un peu de lecture) qui on va le voir sera un peu plus fastidieux à gérer qu'en FPGA. Pourquoi ? Parce que les architectures sont différentes et que l'Arduino ne permet pas faire de vrai parallélisme ce qui complique la tâche de rafraîchissement des digits. Heuresement, grâce aux timers vus en Etape 3 on pourra s'en sortir.

Pour rappel, un afficheur 7 segments avec 4 digits nécessiterait 28 pins pour être contrôlé. Une solution pour pallier ce problème et celle adoptée sur le shield est l'utilisation d'un registre à décalage. Les doux souvenirs de vos TP de VHDL devraient vous rappeler qu'un registre décalage permet d'envoyer une donnée bit par bit en conservant les valeurs précédentes dans des registres. Au final, on peut donc plusieurs broches à partir d'une seule.

Sur votre shield il y a deux registres à décalage 8 bits (cf [schematic](https://github.com/rbeaubois/MCE/blob/master/Arduino/ressources/shield_vma209/schematic_vma209.pdf)), un pour la sélection du digit et un pour la gestion des 7 segments d'un digit. En s'aidant des [exemples](https://github.com/rbeaubois/MCE/tree/master/Arduino/ressources/shield_vma209/exemples) et du schematic vous devriez pouvoir vous en sortir.

> **Aide**
> * Une syntaxe utile pour faire correspondre données et caractères à afficher : [switch](https://www.arduino.cc/reference/en/language/structure/control-structure/switchcase/)
> ```C++
> switch(data){
>   case 0        : c = 0x00; break;
>   ...
>   case int('a') : c = 0x00; break;
>   default       : c = 0x00; break;
> }
>```
> * Opérateur utile pour convertir les entiers en caractères
> ```C
> %
>```
> * Envoyer une donnée bit par bit à une horloge donnée : [shiftOut()](https://www.arduino.cc/reference/en/language/functions/advanced-io/shiftout/)
> ```C
> shiftOut(dataPin, clockPin, bitOrder, value)
>```

# Etape 9 : [Relax](https://www.youtube.com/watch?v=Yem_iEHiyJ0)

Pour l'instant le projet s'arrête là mais n'importe quelle amélioration est la bienvenue !

Et si vous êtes arrivés là juste en scrollant et en vous disant que c'est trop dur, que vous n'y arriverez jamais, eh bien il n'y a qu'en essayant et persévérant qu'on peut réussir !

<p align="center">

  <img src="https://media.giphy.com/media/seWgbxf8FqJAgIkptb/giphy.gif">

</p>
