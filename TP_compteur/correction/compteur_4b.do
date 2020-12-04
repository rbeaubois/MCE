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
force clk 0 0, 1 10 -r 20
force rst 1 0, 0 20, 1 600, 0 640
force en 0 0, 1 40, 0 520, 1 560
force inc 1 0, 0 370

run 800