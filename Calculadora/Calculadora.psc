Algoritmo calculadora 
	Definir primerNumero, segundoNumero, total Como real;
	operacionElegida<-0;
	Escribir "Seleccione la operación que desea realizar";
	Escribir "1 = Suma";
	Escribir "2 = Resta";
	Escribir "3 = Multiplicación";
	Escribir "4 = División";
	Leer operacionElegida
	
	Si operacionElegida < 1 O operacionElegida > 4 Entonces
        Escribir "Esta opción no está en el menú, debe elegir entre 1 y 4"
    Sino
		Escribir "Ingrese el primer número";
		Leer primerNumero
		Escribir "Ingrese el segundo número";
		Leer segundoNumero
		
		Si operacionElegida == 1 Entonces
			total<-primerNumero + segundoNumero
			Escribir "El resultado de la suma es:", total
		SiNo
			Si operacionElegida == 2 Entonces
				total<-primerNumero - segundoNumero
				Escribir "El resultado de la resta es:", total
			SiNo
				Si operacionElegida == 3 Entonces
					total<-primerNumero * segundoNumero
					Escribir "El resultado de la multiplicación es:", total
				SiNo
					Si operacionElegida == 4 Entonces
						Si SegundoNumero == 0 Entonces
							Escribir "Error, segundo número divido por cero"
						SiNo 
						total<-primerNumero / segundoNumero
						Escribir "El resultado de la división es:", total
						FinSi
					Fin Si
				Fin Si
			Fin Si
		Fin Si
	Fin Si
	
FinAlgoritmo
