# TP 2 : Algorithmes de tri
---

> Par Wolodia Zdetovetzky & Yannis Tessier        
> CPE Lyon - 3ICS - année 2021 - 2022     
> Développement Informatique

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
Le document `libs/generateArray.c` contient la méthode permettant la création de tableaux aléatoires.

## Compilation et génération de la documentation

Pour générer les fichiers permettant la compilation du projet il faut faire les commandes suivantes

  ```bash
  md build
  cd build 
  cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_DEPENDS_USE_COMPILER=FALSE -G "CodeBlocks - MinGW Makefiles" ..
  make all
  ```

L'executable se situe dans le dossier build.``

## Les commandes

Pour que le script s'exécute correctement, il faut lui préciser un fichier de sortie.

  ```bash
  Benchme.exe <output_file.csv>
  ```

## Résultats attendus

Le script va renvoyer dans le fichier de sortie, les différents temps, des différents algorithmes de tri.

Soit, le trie a bulle, le tri par selection, le trie par insertion et le trie par tas.

Pour obtenir des résultats plus fiable, le temps est calculé pour chaque algorithme avec un tableau de meme taille et de meme valeur. 

Des tableaux de tailles différentes vont être générés pour démontrer l'efficacité de certains algorithmes plutot que d'autres.

## Évolutions à venir

- Multi-threading et calcul de temps par thread.
- Graphique de resultats