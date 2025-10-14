name: Tri à bulles naif
input Tab: tableau de nombres
input Taille: Nombre d'éléments dans Tab
Résultat: Tab est trié dans l'ordre croissant
Begin:
Pour i de Taille -1 à 0 faire:
    Pour j de 0 à i faire:
        Si Tab[j] > Tab[j + 1] alors:
            let aux = Tab[j]
            Tab[j] = Tab[j + 1]
            Tab[j + i] = aux
        fin Si
    fin Pour j
end