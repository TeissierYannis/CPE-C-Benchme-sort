# TP 2 : Algorithmes de tri

Par Wolodia Zdetovetzky & Yannis Tessier        
CPE Lyon - 3ICS - année 2021 - 2022     
Développement Informatique

## Description

Ce projet contient l'implémentation de 4 algorithmes de tri (tri à bulles, tri par sélection,
tri par insertion et le tri par tas) s'éxécutant de manière croissante ou décroissante
sur un tableau de chiffres aléatoires à virgules compris entre 0 et 10^6.

Ces 4 algorithmes sont testés dans le `main.c`.     
Chaque algorithme est chronométré en temps, puis une moyenne est faite à partir de 3 tests établis sur des
tableaux aléatoires contenant 10^2, 10^3, 10^4, 10^5, 10^6 et 10^7 valeurs aléatoires.  
Les résultats sont stockés dans le document `output/output.csv`.

La documentation du projet est auto-générée grâce à doxygen.    
Celle-ci est disponible avec le document `doc/html/index.html`

Ces algorithmes sont implémentés à l'aide de méthodes dans les documents.c portant leurs noms : 
- `bubbleSort.c`
- `SelectionSort.c`
- `InsertionSort.c`
- `HeapSort.c`

Leurs méthodes sont référencées dans le document `libs/header.h`.    
Le document `libs/generateArray.c` contient la méthode permettant la création de tableau aléatoires.         


## Les commandes

## Résultats attendus

## Évolutions à venir