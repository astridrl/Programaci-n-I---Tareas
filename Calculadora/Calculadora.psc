Algoritmo calculadora
	Definir primerNumero, segundoNumero, total Como Real
	operacionElegida <- 0
	Escribir 'Seleccione la operaci�n que desea realizar'
	Escribir '1 = Suma'
	Escribir '2 = Resta'
	Escribir '3 = Multiplicaci�n'
	Escribir '4 = Divisi�n'
	Leer operacionElegida
	Si operacionElegida<1 O operacionElegida>4 Entonces
		Escribir 'Esta opci�n no est� en el men�, debe elegir entre 1 y 4'
	SiNo
		Escribir 'Ingrese el primer n�mero'
		Leer primerNumero
		Escribir 'Ingrese el segundo n�mero'
		Leer segundoNumero
		Si operacionElegida==1 Entonces
			total <- primerNumero+segundoNumero
			Escribir 'El resultado de la suma es:', total
		SiNo
			Si operacionElegida==2 Entonces
				total <- primerNumero-segundoNumero
				Escribir 'El resultado de la resta es:', total
			SiNo
				Si operacionElegida==3 Entonces
					total <- primerNumero*segundoNumero
					Escribir 'El resultado de la multiplicaci�n es:', total
				SiNo
					Si operacionElegida==4 Entonces
						Si segundoNumero==0 Entonces
							Escribir 'Error, segundo n�mero divido por cero'
						SiNo
							total <- primerNumero/segundoNumero
							Escribir 'El resultado de la divisi�n es:', total
						FinSi
					FinSi
				FinSi
			FinSi
		FinSi
	FinSi
FinAlgoritmo
