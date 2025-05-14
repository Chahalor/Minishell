# what i have to handle:

## 🧭 Flèches de navigation
 -[X] ← (gauche)		\033[D	Déplacer curseur à gauche
 -[X] → (droite)		\033[C	Déplacer curseur à droite
 -[ ] ↑ (haut)			\033[A	Historique précédent
 -[ ] ↓ (bas)			\033[B	Historique suivant

## 🧻 Édition de ligne
 -[X] Suppr (Delete)	\033[3~				Supprimer le caractère sous le curseur
 -[ ] Home				\033[H ou \033[1~	Début de ligne
 -[ ] End				\033[F ou \033[4~	Fin de ligne
 -[ ] Ctrl+Left			\033[1;5D			Aller au mot précédent (ou autre selon terminal)
 -[ ] Ctrl+Right		\033[1;5C			Aller au mot suivant (idem)

## 🧷 Séquences "bracketed paste"
 -[ ] Début de collage	\033[200~
 -[ ] Fin de collage	\033[201~