Rapport de Projet : Développement d'un Jeu d'Aventure 2D
## Organisation du projet

### Classes principales
- **Moteur**  
  Gère la fenêtre, les événements clavier, le temps et le rendu graphique.

- **Image**  
  Permet de charger et d’afficher des images complètes ou des parties de feuilles de sprites.

- **Personnage**  
  Classe centrale regroupant l’image, la position, la direction, les déplacements,
  les collisions et la gestion des animations.

- **Avatar**  
  Personnage contrôlé par le joueur via le clavier.

- **Ennemi**  
  Personnage contrôlé automatiquement par le programme.

- **Tuile**  
  Décrit un type d’objet du jeu (nom, position dans la feuille de sprites, propriété).

- **Dictionnaire**  
  Charge les définitions des tuiles depuis un fichier texte et permet une recherche efficace
  par recherche dichotomique.

- **Objet**  
  Représente une instance d’un objet placé dans le niveau à une position donnée.

- **Niveau**  
  Gère le décor, les collisions avec les murs, les bonus et la condition de victoire.

---

## Boucle de jeu
La boucle principale du jeu est organisée en trois étapes :
1. Gestion des événements (entrées clavier)
2. Mise à jour de la logique du jeu (déplacements, collisions, animations)
3. Rendu graphique (affichage du fond, du niveau et des personnages)

Cette organisation garantit un fonctionnement fluide et structuré du jeu.

---

## Choix de conception
- Utilisation de la **composition** (`Avatar` et `Ennemi` contiennent un `Personnage`)
  afin de factoriser la logique commune.
- Séparation claire entre la logique du jeu et l’affichage.
- Chargement des niveaux et des objets depuis des fichiers texte pour faciliter l’extension du jeu.
- Centralisation des tests de collision dans la classe `Personnage` et `Niveau`.

---

## Fonctionnalités principales
- Déplacement de l’avatar avec les flèches directionnelles
- Chargement et affichage d’un niveau depuis un fichier texte
- Gestion des collisions avec les murs
- Déplacement automatique des ennemis
- Collecte de bonus
- Condition de victoire et de défaite

---

## Fonctionnalités optionnelles réalisées

- **Pause en fin de partie**  
  Une pause est ajoutée avant la fermeture du jeu lorsque le joueur perd ou gagne,
  grâce à la méthode `Moteur::attendre`.

- **Affichage différencié de la fin de partie**  
  Une image spécifique est affichée selon l’issue du jeu :
  - `gameover.png` en cas de défaite
  - `bravo.png` en cas de victoire

- **Animations de marche**  
  Les personnages utilisent une animation de marche basée sur une feuille de sprites.
  L’animation alterne entre plusieurs images selon la direction,
  mise à jour uniquement lorsque `animationsAmettreAjour` renvoie `true`.

- **Disparition des bonus collectés**  
  Les bonus disparaissent visuellement du niveau lorsqu’ils sont collectés par l’avatar,
  grâce à la propriété `cache`.

- **Condition de victoire avancée**  
  Le niveau conserve le nombre de bonus restants.
  Lorsque ce nombre atteint zéro, le jeu se termine automatiquement par une victoire.

- **Déplacements ennemis dynamiques**  
  Les ennemis se déplacent automatiquement dans le niveau,
  avec une gestion du temps pour limiter leur vitesse.

---

Contrôles :

HAUT / BAS / GAUCHE / DROITE : Déplacement de l'avatar.

ECHAP : Quitter proprement le programme.


Bamazi Glory et Mohamed Khalil Ben Hamza