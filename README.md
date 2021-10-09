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

À la sortie de ce programme, nous attendons les résultats des tests dans le document `output/output.cvs`.       
Le document contient la moyenne de temps d'exécution des différents algorithmes sur 3 tableaux de données
aléatoires différents, pour chaque taille de tableau souhaitées (100 à 10^7).       

Après analayse, nous remarquons :
- Sur de faibles volumes de données, tous les alogirithmes se valent en efficacité.
- Plus le volume de données augmentent, plus la différence d'efficacité se ressent.
- On peut ainsi établir le classement d'éfficacité de ces 4 algorithmes suivants :


     1 - tri à bulles   
     2 - tri par sélection   
     3 - tri par insertion   
     4 - tri a bulles   

Une chose est notable : malgré les grand volumes de données, le tri par tas reste toujours extrèmement efficace.
Son temps d'exécution n'explose pas, contrairement à toutes les autres méthodes (voir graphique ci-dessous).

// TODO

## Évolutions à venir

Pour la suite du projet, d'autres algorithmes de tri peuvent être implémentés, 
pour étoffer la bibliothèque disponible.        
La précision des tests peut également être améliorée en utilisant davantage de tableaux aléatoires par exemple,
ou bien en récoltant des données sur un volume encore plus important de données.        
Les méthodes écrites dans ce projet ont également pour vocation à être réutilisées
dans d'autres projets nécessitant leur appel.
