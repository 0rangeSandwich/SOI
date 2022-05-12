#!/bin/bash
./stee paracifrar < ~/PCL/dev/CO2 | ~/PCL/Proyectos/P02/A02.2/./MCPV
~/PCL/Proyectos/P02/A02.3/./encriptador < paracifrar salidacifrada
rm paracifrar
echo "Resultado exitoso" 
