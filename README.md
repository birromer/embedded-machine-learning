[[_TOC_]]

# Embedded Machine Learning

Ce projet GitLab est la base du code que vous devez rendre sur Moodle. Il faut en respecter l'esprit et l'organisation.


# Embarquer la prédiction issue de l'apprentissage automatique ?

L'idée fondamentale de ce cours est de poser la problématique 
de l'**utilisation de l'apprentissage automatique sur une cible quelconque** (ordinateur, smartphone, carte avec ou sans OS, FPGA).

- Peut-on embarquer des algorithmes de prédiction issus de l'apprentissage automatique ?
- Si oui, comment faire ? 
- Quels sont les éléments nécessaires à la prédiction embarquée ?
- Peut-on les rendre minimaux en termes de ressources (puissance de calcul, mémoire, énergie) ?

Ce cours tente d'apporter des réponses à ces questions en apparence simples.

La question de la minimalité des ressources utilisées pour exécuter un calcul rejoint la problématique de la consommation d'énergie (fabrication, fonctionnement et recyclage) et donc celle du développement durable.  

D'une manière générale, moins on fait appel aux appels systèmes d'un OS, moins on fait appel à des bibliothèques, moins on utilise de ressources, plus le système est minimal. Encore faut-il pouvoir garantir son efficacité...

Au niveau des algorithmes, il faudrait pouvoir isoler uniquement les éléments nécessaires à l'exécution de l'IA. Est-ce possible ? Il faut alors s'interroger sur les étapes nécessaires selon la nature de l'algorithme d'apprentissage choisi :

- Faut-il privilégier une approche algorithmique classique ou une approche de type apprentissage supervisé ou non supervisé ?
- Peut-on distinguer des phases dans ce processus (formatage des données d'entrée ou de sortie, extraction de paramètres, entraînement, prédiction) et peut-on les isoler ? Doit-on toutes les implémenter sur la cible ? 
- Peut-on schématiser ce flux de données et préciser les interfaces nécessaires aux calculs ?

Au niveau des ressources nécessaires, on peut s'interroger :

- A-t-on besoin de langages de haut niveau interprétés ?
- Faut-il un OS ?
- Faut-il un processeur capable ?  
- Quelle puissance de calcul est requise ?

# Contexte d'apprentissage

Pour illustrer ces problématiques, un contexte principal a été choisi : **la reconnaissance de styles musicaux**.

Il s'agit de pouvoir prédire, d'après un extrait musical de 30 secondes, le style de musique de celui-ci.

Nous disposons pour cela de plusieurs bases de données. La plus simple à utiliser, même si celle-ci n'est pas parfaite, est la collection GTZAN disponible sous différents formats (.au ou .wav). L'ensemble de données se compose de 1000 pistes audio de 30 secondes, de 10 styles différents, chacun représenté par 100 pistes. Les pistes sont toutes des fichiers audio monocanal, échantillonnés sur 16 bits à la fréquence de 22050 Hz.

Les styles musicaux sont :
0. blues 
1. classique 
2. country 
3. disco 
4. hiphop 
5. jazz 
6. metal 
7. pop 
8. reggae 
9. rock

# Standards

Ce projet utilise nécessairement :
- un compilateur C++ à la norme 20,
- cmake (>=3.16),
- Python 3.9 et Scikit Learn.

CMake est utilisé pour construire les exécutables du projet. L'utilisation d'un compilateur local, d'un cross-compilateur ou d'un compilateur distant (sur la cible) est à paramétrer dans les préférences de CLion directement (Build > Toolchains).
On pourra ajouter dans chaque répertoire le code Python nécessaire au projet. Par exemple, dans le répertoire SVM, on peut ajouter un répertoire Python qui contient le code pour calculer les coefficients d'une SVM optimale, adaptée au problème.

**Il est très vivement recommandé d'utiliser CLion comme IDE et gcc comme compilateur.**.

# Cible

Nous avons choisi de vous faire travailler sur Raspberry PI 4, avec un OS Linux 64 bits et avec le standard C++-20.

Cette cible a le mérite d'être commode, peu onéreuse et malgré tout pertinente pour notre étude car le processeur est un Broadcom BCM2711, Quad core Cortex-A72 (ARM v8) 64-bit SoC @ 1.5GHz.
Le standard C++-20 permet d'aborder dans un cadre sûr et efficace les problématiques de calcul numérique. 
Linux sera juste pratique dans le cadre de nos exercices et pourrait être supprimé des ressources nécessaires pour peu qu'on mette les mains dans le cambouis ;)

Il sera possible d'ajouter à ces éléments TensorFlow Lite et d'autres outils dédiés à l'IA et l'embarqué.

[L'image du système de la RPI4 se trouve ici !](https://filesender.renater.fr/?s=download&token=bec2a806-8836-4abc-a8bb-ba0215291984).

# Répertoires

## DATASETS

DATASETS contient les ensembles de données utilisées pour apprendre et tester les algorithmes implémentés. 
Pour le dépôt Git, on n'a pas gardé tous les extraits musicaux, afin de na pas encombrer inutilement les disques.
[À vous de télécharger les données complètes ici au format AU.](http://marsyas.info/downloads/datasets.html) 

## Helpers 

Helpers contient un ensemble de fonctionnalités utiles au développement :
- **au_reading.h** et **wav_reading.h** Lire des fichiers .wav ou .au ,
- **print_helpers.h** Afficher des vecteurs ou des tableaux facilement ,
- **file_helpers.h** Sélectionner des fichiers pour l'entraînement et le test et en garder la trace,
- **signal.h** Calculer une transformée de Fourier rapide,
- **music_style_helpers.h** Manipuler facilement des styles sous la forme d'un énuméré plutôt que des entiers.
- **etypes.h** Définir des types ad-hoc pour le signal (DataVector) et les features et avoir la possibilité de compiler rapidement en simple ou en double précision.
- **globals.h** Définir des variables globales.


## Extraction

Ce répertoire contient un cadre de code pour l'extraction de paramètres. 
Celle-ci est nécessaire sur votre machine et sur la cible : en effet, pour prédire une classe d'appartenance, le système embarqué doit être capable de générer les paramètres. 

Tel quel, l'exécutable de ce répertoire produit un fichier de paramètres au format CSV (dans cmake-build-debug/Extraction) formaté avec entêtes. **Il est donc inutile de modifier les sections qui ne comportent pas de //TODO**. Ces sections sont repérables facilement sous CLion (en vert clair dans le code ou en liseret dans l'ascenceur). 

Chaque colonne est nommée et le nom désigne un paramètre particulier : 
- BINAVG3 est la moyenne du bin 3 de la STFT partiquée sur un échantillon de musique.
- BINSTDEV252 est l'écart type du bin 252 de la STFT pratiquée sur un échantillon de musique. 

Chaque ligne se termine par le style de la musique et le chemin vers le fichier. 


Par exemple :

```
BINAVG0,BINAVG1,BINAVG2,BINAVG3,...., BINSTDEV252,BINSTDEV253,BINSTDEV254,BINSTDEV255,Style,FileName
0, 0, 0, 0, 0, 0, 0, 0, .....0, 0, 0, 0, 0, "blues","../../DATASETS/Music/blues/blues.00000.au"
```

Si d'autres paramètres devaient être créés, il suffit :
1. de leur conférer un nom dans l'énuméré FTYPE (etypes.h),
2. de les calculer,
3. de les insérer dans la variable feature d'après leut type. 
`std::map<FTYPE, DataVector> features;`

Ils seront automatiquement inscrits dans le fichier généré par write_csv. 

## Autres répertoires 

- CART : élaborer un arbre de décision CART, générer le code automatiquement et implémenter la prédiction sur la cible.
- RF : élaborer une forêt d'arbre de décision pour améliorer les performances de CART, générer le code automatiquement et implémenter la prédiction sur la cible.
- SVM : élaborer un séparateur à vaste marge optimal et implémenter la prédiction sur la cible.
- ANN : élaborer un réseau de neurones artificiel optimal, implémenter le réseau en C++ pour prédire sur la cible.  


# Objectifs et évaluation --> 18/01/2022

## Programmation des séances 

- Présentation du cours (1h)
- Extraction des paramètres via STFT (3h) pour utilisation avec tous les algorithmes suivants.
- Arbre de décision (2h) : 
  - élaboration d'un arbre de décision de type CART (Python brut et sklearn),
  - génération automatique du code de prise de décision en C++,
  - programmation sur la cible,
  - tests sur la cible.
- Séparateur à Vaste Marge (SVM) (3h) :
  - élaboration du classificateur, 
  - extraction des coefficients,
  - programmation de la prédiction sur la cible,
  - tests sur la cible. 
- Réseaux de neurones (ANN) (3h)
  - élaboration du classificateur,
  - programmation de la prédiction sur la cible,
  - tests sur la cible.
- Améliorations (4h)
  - MFCC plutôt que STFT pour limiter le nombre de paramètres d'entrée,
  - Implémentation de la prédiction via Random Forest en C++. 
  - Utiliser le paradigme objet pour programmer les réseaux de neurones en C++.
  - Programmer sur la cible en utilisant le moteur TensorFlow Light. 
  
## Objectifs :

1. (obligatoire) Implémenter en C++-20 
   1. en utilisant la bibliothèque standard
   2. sans utiliser de bibliothèques externes
   3. sur votre machine et sur la cible embarquée (dans notre cas Raspberry Pi 4). 
2. (obligatoire) Veiller à donner la preuve que le code fonctionne sur la cible. 
3. (obligatoire) Évaluer (et mesurer) les complexités temporelle et mémoire de vos algorithmes. 
4. (obligatoire) Vérifier la performance de chaque classificateur embarqué sur les fichiers de test sélectionnés avant l'entraînement afin de les comparer.
5. Programmer une extraction de paramètres en C++ performante :
   1. (obligatoire) compléter le fichier au_reading.h afin de [convertir les fichiers AU du dataset en DataVector en C++](https://en.wikipedia.org/wiki/Au_file_format).
   2. (obligatoire) efficace dans son exécution (1 Go de données musicales peuvent être traitées en 60 secondes ou moins), 
   3. minimale en termes de paramètres significatifs générés pour l'apprentissage : 
      1. (obligatoire) approche STFT 
      2. (facultatif) approche MFCC  
6. Programmer des arbres de décision :
   1. (obligatoire) générer automatiquement le code C++ à compiler pour exécuter la prise de décision sur la cible depuis le CART Python fourni. 
   2. (facultatif) proposer un implémentation de CART en C++-20 à partir de celle proposée en Python. 
   4. (facultatif) proposer un algorithme de type Random Forest à partir du code de CART C++. 
7. Programmer une SVM :
   1. (obligatoire) Élaborer une SVM optimale à l'aide de Scikit Learn, à partir des paramètres extraits en C++. 
   2. (obligatoire) Implémenter la prédiction un contre un SVM en C++-20 sur la cible.
8. Programmer un réseau de neurones :
   1. (obligatoire) Implémenter un ANN en C++.
   2. (facultatif) Implémenter un ANN en C++ en utilisant le paradigme objet. 
9. (facultatif) Comparer vos implémentations avec TensorFlow sur Raspberry Pi.
10. (obligatoire) Comparer les approches et faire un tableau synthétique des caractéristiques et des performances de chacune approche SVM à une approche NN. 

## Évaluation pour le 18/01/2022 (dépôt Moodle) :

- Rapport au format PDF police 11 de 10 pages maximum qui rend compte précisément de votre travail.
- Le code source (C++/Python/Matlab) 
