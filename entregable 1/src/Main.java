import java.util.Arrays;
import java.util.Scanner;

import Clases.Jugador;
import Clases.Equipo;

public class Main {
    public static void main(String[] args) {
        // Guardo la cantidad de casos de test que voy a tener en una variable.
        System.out.println("ingrese la cantidad de casos de test: ");
        /* como a priori la primer línea es la # casos... */
        String primeraLinea = "";

        /* declaro variables útiles */
        int cant_equipos;
        int caso;


        try (Scanner scanner = new Scanner(System.in)) {
            primeraLinea = scanner.nextLine();
            cant_equipos = Integer.parseInt(primeraLinea);
            caso = Integer.parseInt(primeraLinea);

            Equipo[] equipos = new Equipo[cant_equipos];

            for (int i = 0; i < cant_equipos; i++) {
                equipos[i] = new Equipo(); // Initialize Equipo object
                String[] jugadorData = scanner.nextLine().split(" ");
                String nombre = jugadorData[0];
                int ataque = Integer.parseInt(jugadorData[1]);
                int defensa = Integer.parseInt(jugadorData[2]);

                Jugador jugador = new Jugador(nombre, ataque, defensa);

                equipos[i].insertarJugador(jugador);

            }
        }

    }
}
