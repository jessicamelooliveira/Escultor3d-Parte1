#!/bin/bash

# Define o caminho do README
README_PATH="README.md"

# Pega a data e hora atuais no formato desejado (exemplo: 14 de dezembro de 2024)
DATE=$(date '+%d de %B de %Y, %H:%M')

# Substitui a data no README.md (Assumindo que há um marcador no README.md como "Última modificação: [DATA]")
sed -i "s/Última modificação:.*/Última modificação: $DATE/" $README_PATH

# Adiciona e faz commit do README.md
git add $README_PATH
git commit -m "Atualizar a data da última modificação"

# Agora faz o push para o repositório
git push origin master
