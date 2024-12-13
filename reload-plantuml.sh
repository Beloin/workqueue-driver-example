inotifywait -e close_write,moved_to,create -m . |
while read -r directory events filename; do
  if [ "$filename" = "diagram.puml" ]; then
    plantuml diagram.puml
  fi
done
