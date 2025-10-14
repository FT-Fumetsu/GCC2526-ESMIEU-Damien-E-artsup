name: Tri à bulles naif
input Tab: tableau de nombres
input Taille: Nombre d'éléments dans Tab
Résultat: Tab est trié dans l'ordre croissant
Begin:
let trié = faux
Tant que trié = faux faire:
    trié = vrai
    Pour i de 0 à Taille -1 faire:
        Si Tab[i] > Tab[i + 1] alors:
            let aux = Tab[i]
            Tab[i] = Tab[i + 1]
            Tab[i + 1] = aux
            trié = faux
        fin si
    fin pour
end