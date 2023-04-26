#!/bin/bash

dir=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cd "$dir"

for lang in LAN_EN LAN_NL LAN_DE LAN_FR LAN_ES LAN_IT LAN_LA; do
    wine tasm32.exe -t80 -b -i -dTI83P -d$lang beta.asm /tmp/beta.bin || exit 1
    java -jar "Binary_Linker.jar" -o /tmp/beta.bin dist/beta-en.8xp ZBETA 83p || exit 1

    wine tasm32.exe -t80 -b -i -dTI83 -d$lang beta.asm /tmp/beta.bin || exit 1
    java -jar "Binary_Linker.jar" -o /tmp/beta.bin dist/beta-en.83p ZBETA 83 || exit 1
done
for lang in en ln de fr es it la; do
    rm dist/beta-3.0-ti83p-$lang.zip dist/beta-3.0-ti83-$lang.zip
    (cd dist && zip beta-3.0-ti83p-$lang.zip ABETA.8xp beta-$lang.8xp ../gpl-3.0.txt)
    (cd dist && zip beta-3.0-ti83-$lang.zip BETA.83p ZASMLOAD.83p beta-$lang.83p ../gpl-3.0.txt)
done
