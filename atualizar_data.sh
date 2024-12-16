#!/bin/bash

README_PATH="README.md"
DATE=$(date '+%d de %B de %Y, %H:%M')

sed -i "s/Última modificação:.*/Última modificação: $DATE/" $README_PATH

git add $README_PATH
git commit -m "Atualizar a data da última modificação"
git push origin master

echo "Digite a mensagem de commit"
read mensagem

git add .
git commit -m "Atualização $mensagem"
git push origin master