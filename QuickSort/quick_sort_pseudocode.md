name: QuickSort
input tab: tableau de nombre
input début: premier indice du tableau à partir duquel on effectue le tri
input fin: dernier input du tableau
résultat: on tri le tableau dans l'ordre croissant
BEGIN:
    Si début >= fin alors:
        retourner;
    fin si
    let indicePivot = partition(tab, début, fin)
    si indicePivot > 0 alors:
        QuickSort(tab, début, indicePivot - 1);
    fin si
    QuickSort(tab, indicePivot + 1, fin);
END;