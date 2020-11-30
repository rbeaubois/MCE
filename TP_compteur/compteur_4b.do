## Création de la librairie de travail
#vlib work
#
## Compilation du fichier source
#vcom compteur_4b.vhd
#
## Lancement du simulateur
#vsim work.compteur_4b
#
## Ouverture de la fenêtre Wave
#view wave
#
## Ajout des signaux du circuit dans la fenêtre wave
#add wave –r /*

# Génération du vecteur de test
force ... ..., ... -r ...
force ... ..., ... -r ...
force ... ..., ... -r ...
force ... ..., ... -r ...

run ...