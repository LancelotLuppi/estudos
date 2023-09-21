package a.Primeira_aula;

public class Teste {

	int contador;

	public static void main(String[] args) {

		FichaInscricao f1 = new FichaInscricao();

		f1.setNome("João da Silva");

		f1.setEndereco("Rua Ensolarada, nro 123");
		f1.setCidade("Farroupilha");
		f1.setEstado("RS");
		f1.seteMail("jsilva@google.com");
		f1.setTelefone("54 787668871");

		FichaInscricao f2 = new FichaInscricao("Maria Angélica", "Av. Tomazini, 456", "Bom Princípio", "RS",
				"mangel@ucs.br", "55 45678905");

		FichaInscricao f3 = new FichaInscricao("Airton Madureira", "55 990822347");

		f3.setPago(true);

		f1.mostraInscricao();
		System.out.println();
		f2.mostraInscricao();
		System.out.println();

		f3.mostraInscricao();

	}

}