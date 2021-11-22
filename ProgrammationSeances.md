# Programmation des séances

1. Présentation du cours (1h)
2. Extraction des paramètres des fichiers audio (3h) :
    - **extraction des données brutes d'un fichier .au**,
    - création d'un jeu de paramètres pour l'entrainement des algorithmes :
      - **via STFT, moyennage et écart type**,
      - via MFCC, moyennage et écart type. 
3. Arbre de décision (2h) :
    - **élaboration d'un arbre de décision de type CART** (Python brut et sklearn),
    - **génération automatique du code de prise de décision en C++**,
    - **programmation et test de la prédiction sur la cible**.
    - extension de la solution aux Random Forests. 
4. Séparateur à Vaste Marge (SVM) (3h) :
   - **élaboration du classificateur**,
   - **extraction des coefficients d'un classificateur optimal**,
   - **programmation et test de la prédiction sur la cible**.
5. Réseaux de neurones (ANN) (3h)
   - **élaboration du classificateur**,
   - **programmation et test de la prédiction sur la cible**.
6. Améliorations, optimisation et mesure des performances (4h)
   - **mesure et comparaisons des performances obtenues en terme de temps d'exécution, d'espace mémoire statique et dynamique nécessaire**,
   - **analyse des résultats et conclusion**,
   - MFCC plutôt que STFT pour limiter le nombre de paramètres d'entrée,
   - Implémentation de la prédiction via Random Forest en C++,
   - Utiliser le paradigme objet pour programmer les réseaux de neurones en C++ d'une manière générique,
   - Programmer sur la cible en utilisant le moteur TensorFlow Light.
