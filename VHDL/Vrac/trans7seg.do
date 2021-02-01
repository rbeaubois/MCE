## Création de la librairie de travail
#vlib work
#
## Compilation du fichier source
#vcom trans7seg.vhd (nom du fichier)
#
## Lancement du simulateur
#vsim work.trans7seg
#
## Ouverture de la fenêtre Wave
#view wave
#
## Ajout des signaux du circuit dans la fenêtre wave
#add wave –r /*

# Génération du vecteur de test
force bin(0) 0 0, 1 100 -r 200
force bin(1) 0 0, 1 200 -r 400
force bin(2) 0 0, 1 400 -r 800
force bin(3) 0 0, 1 800 -r 1600

run 1600