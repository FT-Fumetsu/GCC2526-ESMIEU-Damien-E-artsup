# GCC2526-ESMIEU-Damien-E-artsup
I) 
A)Pistes de réflexion
1) Dans les 2 cas, le PGCD est 12 car dans PGCD(a,b) quand (a=0 et b!=0) ou (b=0 et a!=0), 0 = 0xb ou 0xa donc PGCD = |12|
2) Vu que l'algorithme diminue toujours la plus grande des 2 valeurs et que les 2 nombres sont strictements positifs (abs(a) et abs(b)) ils sont bornés par 0 car pour que a - b = 0 il faut que a = b. Ainsi l'algorithme finira toujours par atteindre a = b.
B)Piste d'implémentation
Résultats obtenus à l'exécution de `pgcd_sub.cpp` :
"PGCD(12, 18) = 6
PGCD(-12, 18) = 6
PGCD(12, -18) = 6
PGCD(-12, -18) = 6
PGCD(7, 13) = 1
PGCD(17, 17) = 17
PGCD(0, 5) = 5
PGCD(5, 0) = 5
PGCD(100, 25) = 25
PGCD(25, 100) = 25
PGCD(13, 26) = 13
PGCD(14, 15) = 1
PGCD(1000000000, 500000000) = 500000000
PGCD(1836311903, 1134903170) = 1"

Et pareil pour les résultats de `pgcd_mod.cpp`
4) La version avec modulo est plus rapide car elle utilise la division euclidienne et que la division est une opération plus rapide que la soustraction.
5) Si on utilise des nombres très grands, modulo sera beaucoup plus rapide que la version avec les soustractions. Ensuite la limite de grand nombre viendra dépendant de si on utilise des int, des long ou des long long.

II) 
A)Pistes de réflexion
1) Tout nombre x ∈ Z mis à la puissance 0 tels que x^0 vaudra toujours 1.
2) si x = 0 et n > 0 tel que x^n alors le résultat sera toujours 0 car x^n vaut une multiplication x par lui même un n nombre de fois. Ainsi 0 fois lui même vaudra toujours 0
B) Piste d'implémentation
Résultats obtenus plus vite avec `pow_fast` qu'avec `pow_naif` :
"1
0
0
0
0
0
1
1
1
1
1
1
1
2
4
8
32
1024
1
-5
25
-125
-3125
9765625
1
7
49
343
16807
282475249
1
-8
64
-512
-32768
1073741824"

III)
A)Pistes de réflexion
1) On s’arrête dès que (r+1)^2 > n parce que la fonction carré est croissante: ainsi si le dernier succésseur dépasse n, alors tous les prochains dépasserons n aussi, donc r est le plus grand entier. Ce qui est la définition d'une racine carrée entière.
