## Création de la librairie de travail
#vlib work
#
## Compilation du fichier source
#vcom dec24.vhd (nom du fichier)
#
## Lancement du simulateur
#vsim work.dec24
#
## Ouverture de la fenêtre Wave
#view wave
#
## Ajout des signaux du circuit dans la fenêtre wave
#add wave –r /*

# Génération du vecteur de test
force a(0) 0 0, 1 100 -r 200
force a(1) 0 0, 1 200 -r 400
force en 0 0, 1 400 -r 800

run 800