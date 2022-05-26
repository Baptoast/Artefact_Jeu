# /!\ Jeu en cours de développement, pas encore opérationnel /!\
# Artefact_Jeu
## But du jeu : 
Faire tomber les points de vie de vos adversaires à 0

### Nombres de joueurs :
2 à 4 joueurs

### Comment jouer ?
(Vous rejoindrez directement une salle au menu de selection si le serveur est disponible lorsque vous lancez le jeu)

#### Menu de selection
Ici vous pouvez choisir 1 des 4 personnages disponibles, et annoncé aux autres joueurs que vous êtes prêt pour jouer.
La partie commencera lorsque tout les joueurs de la salle aurons annoncés qu'ils sont prêt (il faut au minimum 2 joueurs pour que le jeu ce lance).

#### Jeu
Lorsque vous commencez une nouvelle partie vous apparaitrez dans un des quatres coins de la map (choisi en fonction de votre n° de joueur).

##### Déroulement d'un tour :
Chaque tour ce déroule en plusieurs phase, la phase **actions** et la phase **résolution**.

1) La phase **actions**

Vous avez le choix d'effectuer deux actions parmis quatre proposés : **Se déplacer**, **Fouiller**, **Utiliser un objet** ou **Déclencher un éboulement**

- **Se déplacer** : Permet à votre personnage de ce déplacer de 0 à 3 cases, vous selectionnez les cases une par une, et une fois le choix effectué, un clone bleuté de votre personnage vous indique la futur position qu'aura (probablement) votre personnage lors de la résolution de cette action.

- **Fouiller** : Permet à votre personnage de récupérer un objet ou de récupéré un fragment d'artéfact si celui-çi ce trouve sur votre case.

- **Utiliser un objet** : Permet à votre personnage d'utiliser un objet de son inventaire (Arme, Utilitaire ou Piège), la description de l'objet vous renseigne sur sa catégorie et son utilité.

- **Déclencher un éboulement** : Vous permet de choisir une large zone dans laquelle un fragment tombera à coup sûr (aléatoirement), faire cette action aura cependant un risque de faire tomber des obstacles du plafond qui bloquerons le passage, si l'un d'entre eux tombe sur un joueur, celui-çi perd un point de vie.

Une fois deux actions parmis celle-ci dessus choisies (peut être deux fois les mêmes), et que tout les autres joueurs ont choisis également leurs actions, la phase de résolution commence.

2) La phase **résolution**

Chaque personnage effectue leurs premières actions dans l'ordre de l'indicateur à droite, puis leurs seconde action à nouveau dans le même ordre.

Une fois la phase de résolution finie, la phase du choix des actions recommence et ainsi de suite.

### Les personnages

Chaque personnage possède un objet unique qui évolue à chaque fois qu'un adversaire perd tout ses points de vies.

| Personnage | Objet | Niveau 1 | Niveau 2 | Niveau 3 |
| ----------- | ----------- | ----------- | ----------- | ----------- |
| Jon | Loupe | Copie l'effet d'un de vos objets | Détruit un de vos objets pour obtenir 2 fragments d'artéfacts | Vous obtenez un trésor |
| Hélène | Fusil de rechange | Tir 1 projectile qui inflige 2 points de dégâts | Tir 3 projectiles lents qui inflige chacun 2 points de dégâts | Invoque un fusil qui tire des salves de projectiles lents dans un couloir de 3 de largeurs jusqu'à la fin du jeu |
| Mickael | Epée de rechange | Inflige 4 point de dégâts à un adversaire au corp à corp | Piège : inflige 4 point de dégâts | Passif : Vous infligez 1 point de dégâts à chaque personnage qui effectue des actions proche de vous |
| Ten'eia | Livre de sort | Vous rend 2 points de vie | Invoque un monstre avec 3 points de vie qui inflige 1 point de dégât au corp à corp qui ne vous attaque pas | Vous vous divisez en 2 copies, qui partage leurs objets en commun, chaque copie récupère la moitié de la vie original |

### Les objets

Les objets sont divisés en trois catégories : Armes, Utilitaire et Piège.

| Objet | Catégorie | Effet |
| ----------- | ----------- | ----------- |
| Epée antique | Arme | Vous infligez 3 point de dégâts au corp à corp |
| Maillet de l'empereur | Arme | Vous infligez 2 points de dégâts sur deux case proche de vous et repousser les joueurs touchés de 1 cases |
| Sombre faux | Arme | Vous infliger 2 point de dégâts tout autour de vous |
| Pistolet rouillé | Arme | Vous tirez un projectile qui inflige 2 points de dégâts |
| Bombe flash | Arme | Selectionnez une zone hors de votre champ de vision, les joueurs qui ce trouve dans cette zone subisse 1 point de dégâts, la zone est révélé jusqu'à la prochaine résolution |
| Sondeur tek-tonique | Armes | Lance une onde de choc qui inflige 1 point de dégâts dans un couloir de 3 de large qui traverse tout |
| Kit de soin | Utilitaire | Vous rend 1 point de vie |
| Balise des anciens | Utilitaire | Vous placez une balise dans votre champ de vision qui vous donne la vision de la zone tant qu'elle ne se fait pas écrasée |
| Cape d'invisibilité | Utilitaire | Vous devenez invisible jusqu'à la prochaine résolution |
| Pelle perceuse | Utilitaire | Choisissez un obstacle dans votre champ de vision, il est détruit |
| Hologramme trompeur | Utilitaire | Choisissez une case dans votre champ de vision, fait apparaitre un faux obstacle traversable |
| Bombe cachée | Piège | Inflige 2 point de dégâts |
| Fosse camouflée | Piège | Inflige 1 point de dégâts, empêche les déplacements suivants |
| Rocher roulant | Piège | Invoque un rocher qui roule lentement| et pousse les ennemis sur son passage en leurs infligeant 4 point de dégâts. |
| Piège-à-rat | Piège | Invoque 2 rats dans le champ de vision ayant chacun 1 point de vie et infligeant 1 point de dégâts au corps à corps |

### Les artéfacts

Lorsque vous réussissez à réunir 5 fragments d'artéfacts, vous obtenez 1 des 4 artéfacts primordiaux aléatoirement :

A chaque utilisation, l'artéfact gagne en puissance (après un temps de recharge de 2 tours), jusqu'au niveau 3.

| Artéfact | Niveau 1 | Niveau 2 | Niveau 3 | ??????? |
| ----------- | ----------- | ----------- | ----------- | ----------- |
| Conque de l'Atlantide | Tir une vague de projectiles qui inflige 1 point de dégâts dans un couloir de 1 de large | Tir une vague de projectiles qui inflige 1 point de dégâts dans un couloir de 3 de large | Tir une vague de projectiles qui inflige 1 point de dégâts dans un couloir de 5 de large | Tir 4 vague de projectiles dans les 4 directions qui inflige 1 point de dégâts dans des couloirs de 5 de larges |
| Torche des anciens | Tir 1 cercle de feu qui traverse tout et inflige 1 point de dégât | Tir 2 cercles de feu qui traverse tout et inflige 1 point de dégât | Tir 3 cercles de feu qui traverse tout et inflige 1 point de dégât | Tir 3 cercles de feu qui traverse toute la carte et inflige 1 point de dégât |
| Coeur de la Terre | Choisissez une case hors de votre champ de vision, y fait tomber un obstacle | Choisissez une zone hors de votre champ de vision, y fait tomber 5 obstacles | Choisissez une zone hors de votre champ de vision, y fait tomber 9 obstacles | Choisissez une zone, y fait tomber 9 obstacles |
| Statuette efflorescente | Passif : Avant chaque première action, fait apparaitre 1 plante sur une des cases de votre champs de vision, au bout de 10 plantes, vous récupérez également 1 point de vie et les autres joueurs subissent 1 point de dégâts au début de leurs premier tour | Passif : Avant chaque première action, fait apparaitre 2 plante sur une des cases de votre champs de vision, au bout de 10 plantes, vous récupérez également 1 point de vie et les autres joueurs subissent 1 point de dégâts au début de leurs premier tour | Passif : Avant chaque première action, fait apparaitre 3 plantes sur une des cases de votre champs de vision, au bout de 10 plantes, vous récupérez également 1 point de vie et les autres joueurs subissent 1 point de dégâts au début de leurs premier tour | Passif : Avant chaque première action, fait apparaitre 5 plantes sur une des cases de votre champs de vision, au bout de 10 plantes, vous récupérez également 1 point de vie et les autres joueurs subissent 1 point de dégâts au début de leurs premier tour | 

### Information supplémentaire :

- Chaque joueur commence avec 4 points de vies.
- Seul l'objet au premier emplacement d'un joueur n'est pas visible par les autres.
- Lorsqu'un obstacles tombe sur une case autre qu'un joueur, tout les composants ce situant sur la case reste quand même (ex : piège)
- Lorsqu'un joueur perd, il voit toute la map, tout les pièges et tout les objets des joueurs (pour de l'équitée, évité de révélé des informations)
- Chaque fois qu'un fragment d'artéfact apparais, sa position est révélé à tout le monde
- Il ne peux pas avoir plus de 1 fragment d'artéfact sur le sol en même temps.
- On peux continuer à récupérer des fragments d'artéfacts même après avoir obtenus un artéfact complété...
- Les joueurs ne peuvent obtenir qu'un artéfact.
- Les artéfacts ne peuvent pas être détruit ou volé.
- Chaque artéfact ne peut être obtenus qu'une seule fois par partie.
- Lorsqu'un joueur perd, son artéfact n'est pas ré-obtenable par les autres joueurs.
- La bulle de discution par émote ne fonctionne pas pour l'instant.
- Lorsqu'un objet est volé/perdu avant d'être utilisé, l'utilisation est annulée.
- Les projectiles ce déplacent avant chaque action du joueur qui les a lancés.
- Lorsque vous éliminer un joueur, vous gagner un fragment d'artéfact
