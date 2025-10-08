PRG="collatz"
SRC="$PRG.cpp"
OUT="build/$PRG"

out_dir="$(dirname "$OUT")"

if [ ! -d "$out_dir" ]; then
  echo "📁 Création du dossier '$out_dir'..."
  mkdir -p "$out_dir" || {
    echo "❌ Erreur : impossible de créer le dossier '$out_dir'." >&2 # Envoie ce message dans les erreurs
    exit 1
  }
else
  echo "✅ Dossier '$out_dir' déjà présent."
fi

echo "🛠️  Compilation..."
g++ "$SRC" -o "$OUT"

if [ $? -eq 0 ]; then
  echo "✅ Compilation réussie. Exécution de '$OUT'..."
  echo "--------------------------------------"
  "$OUT"
  echo "💡 Programme terminé"
else
  echo "❌ Erreur : la compilation a échoué." >&2 # Envoie ce message dans les erreurs
  exit 1
fi
