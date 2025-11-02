name: Insertion
input tab: tableau de nombres
input Taille: Nombre d'éléments dans tab
Résultat: tab est trié dans l'ordre croissant
Begin:
    Pour i de 1 à Taille - 1 faire:
        let clé = tab[i]
        let j = i - 1
        Tant que j >= 0 et tab[j] > clé faire:
            tab[j + 1] = tab[j]
            j = j - 1
        fin tant que
        tab[j + 1] = clé
    fin pour
end