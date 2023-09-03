package b.Sistema_banco;

import java.util.List;

public class Cliente {

    private String nome;
    private String telefone;
    private List<ContaCorrente> contas;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public List<ContaCorrente> getContas() {
        return this.contas;
    }
    public ContaCorrente getContaByIndice(int index) {
        if(index >= 0 && index < 10) {
            return this.contas.get(index);
        } else {
            System.out.println("Indice deve ser maior ou igual à zero e menor ou igual à 10.");
            return null;
        }
    }
    public void setConta(ContaCorrente novaConta) {
        if(!(this.contas.size() == 10)) {
            this.contas.add(novaConta);
        } else {
            System.out.println("Você já atingiu o limite de contas (10).");
        }
    }
}
