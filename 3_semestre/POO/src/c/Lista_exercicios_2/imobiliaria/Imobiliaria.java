package c.Lista_exercicios_2.imobiliaria;

import java.util.List;

public class Imobiliaria {

    private String nome;
    private List<Terreno> terrenos;


    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public List<Terreno> getTerrenos() {
        return terrenos;
    }

    public void setTerrenos(List<Terreno> terrenos) {
        this.terrenos = terrenos;
    }

    public Terreno getTerrenoById(int id) {
        return this.terrenos.get(id);
    }

}
