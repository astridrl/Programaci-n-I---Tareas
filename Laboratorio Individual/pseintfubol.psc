Algoritmo CampeonatoFut
    Definir equipos Como Cadena
	Definir repetirr como logico
    Definir resultados, estadisticas, NUMERO_EQUIPOS, MAX_GOLES, MIN_GOLES Como Entero
    Definir opcion Como Caracter
    Definir i, j Como Entero
	
    // Constantes
    NUMERO_EQUIPOS = 6;
    MAX_GOLES = 10;
    MIN_GOLES = 0;
	
    // Matrices
    Dimension equipos[NUMERO_EQUIPOS]
    Dimension resultados[NUMERO_EQUIPOS, NUMERO_EQUIPOS, 2]
    Dimension estadisticas[NUMERO_EQUIPOS, 7] // [jugados, ganados, empatados, perdidos, golesFavor, golesContra, puntos]
	
	
		repetirr <- Verdadero
			
			Mientras repetirr Hacer
					Limpiar Pantalla
					Escribir "* Campeonato de Fútbol *"
					
					// Inicializar estadísticas
					Para i <- 1 Hasta NUMERO_EQUIPOS Hacer
						Para j <- 1 Hasta 7 Hacer
							estadisticas[i, j] <- 0
						FinPara
					FinPara
					
					IngresarEquipos(equipos, NUMERO_EQUIPOS)
					LlenarResultados(resultados, equipos, NUMERO_EQUIPOS, MAX_GOLES, MIN_GOLES)
					CalcularEstadisticas(resultados, estadisticas, NUMERO_EQUIPOS)
					ImprimirTabla(equipos, estadisticas, NUMERO_EQUIPOS)
					
					Escribir "Desea simular otro campeonato? (s/n): "
					Leer opcion
					Si opcion = "n" Entonces
						repetirr <- Falso
						FinSi
			FinMientras
FinAlgoritmo

// Permite ingresar los nombres de los equipos
SubProceso IngresarEquipos(equipos Por Referencia, NUMERO_EQUIPOS Por Valor)
    Para i <- 1 Hasta NUMERO_EQUIPOS - 1 Hacer
        Escribir "Ingrese el nombre del equipo ", i + 0, ": "
        Leer equipos[i]
    FinPara
FinSubProceso

// Genera o permite ingresar los resultados de los partidos
SubProceso LlenarResultados(resultados Por Referencia, equipos Por Referencia, NUMERO_EQUIPOS Por Valor, MAX_GOLES Por Valor, MIN_GOLES Por Valor)
    Definir modo Como Caracter
    Escribir "Desea ingresar los resultados manualmente (m) o generarlos aleatoriamente (a)?"
    Leer modo
	
    Para i <- 1 Hasta NUMERO_EQUIPOS Hacer
        Para j <- i + 1 Hasta NUMERO_EQUIPOS Hacer
            Si i <> j Entonces
                Si modo = "m" Entonces
                    Repetir
                        Escribir "Ingrese goles de ", equipos[i], " contra ", equipos[j], ": "
                        Leer resultados[i, j, 1]
                    Hasta Que resultados[i, j, 1] >= MIN_GOLES Y resultados[i, j, 1] <= MAX_GOLES
                    
                    Repetir
                        Escribir "Ingrese goles de ", equipos[j], " contra ", equipos[i], ": "
                        Leer resultados[i, j, 2]
                    Hasta Que resultados[i, j, 2] >= MIN_GOLES Y resultados[i, j, 2] <= MAX_GOLES
                Sino
                    resultados[i, j, 1] <- Azar(MAX_GOLES + 1)
					resultados[i, j, 2] <- Azar(MAX_GOLES + 1)
                FinSi
                
                // Partido de vuelta
                resultados[j, i, 1] <- resultados[i, j, 2]
                resultados[j, i, 2] <- resultados[i, j, 1]
            FinSi
        FinPara
    FinPara
FinSubProceso

// Calcula estadísticas de cada equipo
SubProceso CalcularEstadisticas(resultados Por Referencia, estadisticas Por Referencia, NUMERO_EQUIPOS Por Valor)
    Definir i, j Como Entero
    Para i <- 1 Hasta NUMERO_EQUIPOS Hacer
        Para j <- 1 Hasta NUMERO_EQUIPOS Hacer
            Si i <> j Entonces
                estadisticas[i, 1] <- estadisticas[i, 1] + 1  // Partidos jugados
                estadisticas[i, 5] <- estadisticas[i, 5] + resultados[i, j, 1] // Goles a favor
                estadisticas[i, 6] <- estadisticas[i, 6] + resultados[i, j, 2] // Goles en contra
                
                Si resultados[i, j, 1] > resultados[i, j, 2] Entonces
                    estadisticas[i, 2] <- estadisticas[i, 2] + 1  // Partidos ganados
                    estadisticas[i, 7] <- estadisticas[i, 7] + 3  // Puntos por victoria
                SiNo 
                    Si resultados[i, j, 1] < resultados[i, j, 2] Entonces
                        estadisticas[i, 4] <- estadisticas[i, 4] + 1  // Partidos perdidos
                    SiNo
                        estadisticas[i, 3] <- estadisticas[i, 3] + 1  // Partidos empatados
                        estadisticas[i, 7] <- estadisticas[i, 7] + 1  // Puntos por empate
                    FinSi
                FinSi
            FinSi
        FinPara
    FinPara
FinSubProceso

// Muestra la tabla de posiciones
SubProceso ImprimirTabla(equipos Por Referencia, estadisticas Por Referencia, NUMERO_EQUIPOS Por Valor)
    Definir campeon, ultimo, maxPuntos, minPuntos Como Entero
    maxPuntos <- -1
    minPuntos <- 999
    campeon <- 1
    ultimo <- 1
    
    Escribir "Tabla de Posiciones:"
    Escribir "Equipo | PJ | PG | PE | PP | GF | GC | Pts"
    
    Para i <- 1 Hasta NUMERO_EQUIPOS Hacer
        Escribir equipos[i], " | ", estadisticas[i, 1], " | ", estadisticas[i, 2], " | ", estadisticas[i, 3], " | ", estadisticas[i, 4], " | ", estadisticas[i, 5], " | ", estadisticas[i, 5], " | ", estadisticas[i, 6], "|", estadisticas[i, 7]
        
        Si estadisticas[i, 7] > maxPuntos Entonces
            maxPuntos <- estadisticas[i, 7]
            campeon <- i
        FinSi
        
        Si estadisticas[i, 7] < minPuntos Entonces
            minPuntos <- estadisticas[i, 7]
            ultimo <- i
        FinSi
    FinPara
    
    Escribir "Campeón: ", equipos[campeon], " con ", maxPuntos, " puntos."
    Escribir "Último lugar (descenso): ", equipos[ultimo], " con ", minPuntos, " puntos."
FinSubProceso


