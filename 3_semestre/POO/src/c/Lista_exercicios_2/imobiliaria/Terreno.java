package c.Lista_exercicios_2.imobiliaria;

public class Terreno {

    private int id;
    private float lado;
    private float altura;
    private String descricao;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public float getLado() {
        return lado;
    }

    public void setLado(float lado) {
        this.lado = lado;
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        this.altura = altura;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public float calculaArea() {
        return this.lado * this.altura;
    }

    @Override
    public String toString() {
        return "Terreno " + this.getId() + ": \n"
                + "Descriçâo: " + this.descricao + "\n"
                + "Área: " + this.calculaArea() + "\n";
    }
}
