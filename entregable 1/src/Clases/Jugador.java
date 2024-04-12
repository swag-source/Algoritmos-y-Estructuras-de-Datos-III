package Clases;


public class Jugador {
    private String nombre;
    private int ataque;
    private int defensa;

    public Jugador(String nombre, int ataque, int defensa){
        this.nombre = nombre;
        this.ataque = ataque;
        this.defensa = defensa;
    }

    public String getNombre() {
        return nombre;
    }

    public int getAtaque() {
        return ataque;
    }

    public int getDefensa() {
        return defensa;
    }
}

// [[jugador1, ..., jugador n], []]
