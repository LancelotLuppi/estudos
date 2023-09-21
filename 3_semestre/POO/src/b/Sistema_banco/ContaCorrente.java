package b.Sistema_banco;

import java.math.BigDecimal;

public class ContaCorrente {

    private int numero;
    private BigDecimal saldo;

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public BigDecimal getSaldo() {
        return saldo;
    }

    public void setSaldo(BigDecimal saldo) {
        this.saldo = saldo;
    }

    public void deposita(BigDecimal val) {
        if(val.compareTo(BigDecimal.ZERO) > 0) {
            this.saldo.add(val);
            System.out.println("Valor de " + val.intValue() + " depositado com sucesso.");
        } else {
            System.out.println("Não é permitido depositar valores negativos ou iguais à zero.");
        }
    }
    public void saca(BigDecimal val) {
        if(val.compareTo(BigDecimal.ZERO) > 0) {
            if(this.saldo.compareTo(val) >= 0) {
                this.saldo.subtract(val);
                System.out.println("Valor de " + val.intValue() + " sacado com sucesso.");
            } else {
                System.out.println("Saldo insuficiente.");
            }
        } else {
            System.out.println("Não é permitido sacar valores menores ou iguais à zero.");
        }
    }

    @Override
    public String toString() {
        return "Conta " + this.numero + ", saldo: " + this.saldo;
    }
}
