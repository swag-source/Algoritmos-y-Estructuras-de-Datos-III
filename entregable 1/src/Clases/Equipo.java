package Clases;

public class Equipo {
    private Jugador[] equipo;
    private int cantidadJugadores;
    private static final int capacidadJugadores = 10;

    public Equipo() {
        this.equipo = new Jugador[capacidadJugadores];
        this.cantidadJugadores = 0; // Al inicio no hay jugadores en el equipo
    }

    public void insertarJugador(Jugador jugador) {
        if (cantidadJugadores < capacidadJugadores) {
            equipo[cantidadJugadores] = jugador;
            cantidadJugadores++;
        } else {
            System.out.println("El equipo ya está completo, no se puede agregar más jugadores.");
        }
    }

    public Jugador[] getEquipo() {
        return equipo;
    }

    public int getCantidadJugadores() {
        return cantidadJugadores;
    }
}
