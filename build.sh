#!/bin/bash

dir=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cd "$dir"

wine tasm32.exe -t80 -b -i -dTI83P -dLAN_EN beta.asm /tmp/beta.bin || exit 1
java -jar "Binary_Linker.jar" -o /tmp/beta.bin dist/beta-en.8xp ZBETA 83p || exit 1

wine tasm32.exe -t80 -b -i -dTI83 -dLAN_EN beta.asm /tmp/beta.bin || exit 1
java -jar "Binary_Linker.jar" -o /tmp/beta.bin dist/beta-en.83p ZBETA 83 || exit 1
