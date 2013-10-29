Domains

    cod_cliente = integer
    cod_livro   = integer
    idade  		= integer
    genero 		= string
    nome   		= string
	data   		= string    

	lista_str   = string*
	lista_int   = integer*

Database

	     livro(cod_livro,        nome,  genero)
	   cliente(cod_cliente,      nome,  idade)
	emprestimo(cod_cliente, cod_livro,  data)

Predicates

	add_cliente.
	rem_cliente.
	bus_cliente.
/*
	add_livro.
	bus_livro.
	rem_livro.

	carrega.
	salva.

	erro.
*/
	ver_cliente(string)

	qtd(lista_int,integer)
	qtd_clientes(integer)
	qtd_livros(integer)

	boot(integer)
	processa(integer)
	menu(integer, string)


Clauses

	qtd([],0).
	qtd([_|L],N) :- qtd(L,N2), N = N2 + 1.				

	qtd_clientes(N) :- findall(X,cliente(X,_,_),L),
					   qtd(L,N).

	qtd_livros(N) :- findall(X,livro(X,_,_),L),
					   qtd(L,N).					   

	menu(0,_) :- 
			clearwindow,nl,
			write("LOCADORA MAT014"),nl,nl,
			write("1 - Nova"),nl,
			write("2 - Carregar "),nl,
			write("3 - Apagar "),nl,
			write("0 - Sair "),nl,nl,
			write("> "),
			readInt(Op),
			boot(Op).

	menu(1,Locadora) :- 
			clearwindow, nl,
			Nome = Locadora,
		 	write(Nome, " - Locadora"),nl,
		 	write("-----------------"),nl,
		 	write("Adicionar:"),nl,
			write("   1 - Cliente"),nl,
			write("   2 - Livro"),nl,nl,
			
			write("Buscar:"),nl,
			write("   3 - Cliente"),nl,
			write("   4 - Livro"),nl,nl,
			
			write("Remover:"),nl,
			write("   5 - Cliente"),nl,
			write("   6 - Livro"),nl,nl,
			
			write("   0 - Sair"),nl,nl,
			
			write("> "),
			readint(Op),
			processa(Op),
			Op <> 0,
			menu(1,Locadora).


	boot(1) :- clearwindow, nl,
			   write("    Nova Locadora    "),nl,
			   write("---------------------"),nl,
			   write("Nome: "),
			   readln(Nome),
			   concat(Nome,".txt",Result),
			   save(Result),
			   nl,write("Criado com sucesso."),
			   readchar(_),
			   menu(1,Nome),
			   save(Result).
	
	boot(2) :- clearwindow, nl,
			   write("  Carregar Locadora  "),nl,
			   write("---------------------"),nl,
			   write("Nome: "),
			   readln(Nome),
			   concat(Nome,".txt",Result),
			   consult(Result),
			   nl,write("Carregado com sucesso."),
			   readchar(_),
			   menu(1,Nome),
			   save(Result).

	boot(3) :- clearwindow, nl,
			   write("   Apagar Locadora   "),nl,
			   write("---------------------"),nl,
			   write("Nome: "),
			   readln(Nome),
			   concat(Nome,".txt",Result),
			   deletefile(Result),
			   nl,write("Apagado com sucesso."),
			   readchar(_),
			   menu(0,_).

	ver_cliente(Nome) :- cliente(_,Nome,_).

	add_cliente :- clearwindow,nl,
				   write("Adicionar Cliente"),nl,
				   write("-----------------"),nl,
				   write("Nome: "),
				   readln(Nome),nl,
				   not(ver_cliente(Nome)),
				   write("Idade: "),
				   readInt(Idade),
				   qtd_clientes(COD),
				   COD1 = COD+1,
				   assertz(cliente(COD1,Nome,Idade)),
			   	   nl,write("Adicionado com sucesso."),
			   	   readchar(_),!.

	add_cliente :- write("Cliente ja existe."),nl,
				   nl,write("Tecle para continuar..."),
				   readchar(_).

	rem_cliente :- clearwindow,nl,
				   write("Remover Cliente"),nl,
				   write("-----------------"),nl,
				   write("Nome: "),
				   readln(Nome),nl,
				   retract(cliente(_,Nome,_)),
				   /* PARA NAO ATRAPALHAR O COD AUTO */
				   assertz(cliente(0," ",0)),
			   	   nl,write("Removido com sucesso."),
			   	   readchar(_),!.

	rem_cliente :- write("Cliente nao encontrado."),nl,
				   nl,write("Tecle para continuar..."),
				   readchar(_).

	bus_cliente :- clearwindow,nl,
				   write("Buscar Cliente"),nl,
				   write("-----------------"),nl,
				   write("Nome: "),
				   readln(Nome),nl,
				   cliente(COD,Nome,Idade),
				   write("Codigo: ",COD),nl,
				   write("  Nome: ",Nome),nl,
				   write(" Idade: ",Idade),nl,
			   	   nl,write("Tecle para continuar..."),
				   readchar(_),!.

	bus_cliente :- write("Cliente nao encontrado."),nl,
				   nl,write("Tecle para continuar..."),
				   readchar(_).

	processa(0) :- fail.
	processa(1) :- add_cliente.
	processa(3) :- bus_cliente.
	processa(5) :- rem_cliente.
/*
	processa(2) :- add_livro.
	processa(4) :- bus_livro.
	processa(6) :- rem_livro.
	processa(_) :- erro.
*/

Goal
	menu(0,_).
