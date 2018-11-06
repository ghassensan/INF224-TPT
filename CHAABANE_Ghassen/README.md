# INF224

#########################################################

README - INF224 - Projet - 2018/2019

#########################################################

Réalisé par : CHAABANE Ghassen	< ghassen_chaabane@hotmail.fr >

Projet consultable a l'adresse suivante: https://perso.telecom-paristech.fr/elc/inf224/

C'est la réalisation d'un serveur écrit en C++ et d'une interface écrite en JAVA-swing.
Le réprtoire "CHAABANE_Ghassen" contient 3 sous répertoires "cpp", "swing" et "media":
	
	cpp : contient le code du serveur. 
	swing : contient le code du client.
	media : contient 2 fichiers media (photo et video) pour tester l'exemple. 

# Tips
Veuillez suivre les étapes pour réaliser l'exemple.
Nottez bien que les noms utiliser pendant l'utilisation de l'interface graphique sont sensibles à la casse.
Consultez le menu About ("About-us" et "Version") pour s'informer d'avantage à propos notre projet.

# 1.Run server
`cd cpp
make
make run`

Le serveur écoute sur le port 3331 (hardcoded) 

# 2.Run client
`cd swing
make
make run`

# Remarques
## C++
Seules les étapes 12 et 13 n'ont pas été traitées dans mon travail.

### Etape 5 : Traitement générique (en utilisant le polymorphisme) 
Afin de pouvoir traiter chaque objet de la manière adéquate on utilise les fonctions abstraites.

Une fonction virtuelle: est toute fonction supportant être modifiée par une classe fille.

Une fonction abstraite:	est toute fonction nécessitant une définition dans une classe fille pour préciser le comportement aproprié vis à vis sa classe.
une fonction abstraite rend automatiquement la classe abstraite ainsi non instanciable.

### Etape 6 : Films et tableaux
Afin de conserver l'encapsulation des données et préciser les privilèges d'accées, il faut utiliser la copie profonde et rendre la classe immutable.

Si nous voulons impléemnter un accesseur, ce dernier doit retourner un pointeur de type const int*

### Etape 7 : Destruction et copie des objets
Le déstructeur "delete[]" doit être appelé à la destruction d'un objet instancier par l'allocation "new[]".(de même pour "delete" et "new").

### Etape 8 : Créer des groupes
On procède avec une classe groupe qui hérite d'une classe de liste.
On utilise des pointeurs (Multimedia * ) dans la liste car la classe Multimedia contient des méthodes abstraites (donc c'est une classe abstraite qu'on ne peut pas instancier).

### Etape 9 : Gestion automatique de la mémoire
On utilise les "Smart_pointer"
Afin d'interdir l'utilisation de new on déclare le constructeur comme étant une méthode privée et on spécifie les classes amis (friend) ayant accées à l'instanciation des objets de cette classe.

### Etape 10 : Gestion cohérente des données
On crée une classe capable de gérer les objets Multimedia afin d'étblir un nouveau niveau d'abstraction.

### Etape 11 : Client / serveur
On ajoute la méthode processRequest à la classe responsable de la gestion de nos objets.
Cette méthode est appelée chaque fois qu'il y a une requête à traiter.

## Partie Java Swing
C'est la familiarisation avec les outils de Java swing.
Consultez le menu About ("About-us" et "Version") pour s'informer d'avantage à propos notre projet.


#########################################################

FIN - CHAABANE Ghassen - < ghassen_chaabane@hotmail.fr >

#########################################################