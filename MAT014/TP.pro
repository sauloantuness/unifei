Domains

    cod_cliente = integer
    cod_livro   = integer
    idade       = integer
    genero      = string
    nome        = string
    data        = string    

    lista_str   = string*
    lista_int   = integer*


Database

         livro (cod_livro,        nome,  genero)
       cliente (cod_cliente,      nome,  idade)
    emprestimo (cod_cliente, cod_livro,  data)


Predicates

    add_cliente.
    rem_cliente.
    bus_cliente.

    add_livro.
    bus_livro.
    rem_livro.

    lista_clientes.
    lista_livros.

    log_cliente.
    log_livro.

    pegar.
    devolver.

    imprime_Clientes (lista_str).
    imprime_Livros   (lista_str).

    ver_cliente (string)
    ver_livro   (string)

    qtd (lista_int, integer)
    qtd_clientes   (integer)
    qtd_livros     (integer)

    processa (integer)
    boot (integer)
    menu (integer, string)


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

            write("Listar:"),nl,
            write("   7 - Clientes"),nl,
            write("   8 - Livros"),nl,nl,
            
            write("Relatorio:"),nl,
            write("   9 - Cliente"),nl,
            write("  10 - Livro"),nl,nl,
            
            write("Emprestimo:"),nl,
            write("  11 - Pegar"),nl,
            write("  12 - Devolver"),nl,nl,
            
            write("   0 - Sair"),nl,nl,
            write("> "),

            readint(Op),
            processa(Op),

            save(Locadora),

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
               menu(1,Nome).
    
    boot(2) :- clearwindow, nl,
               write("  Carregar Locadora  "),nl,
               write("---------------------"),nl,
               write("Nome: "),
               readln(Nome),
               concat(Nome,".txt",Result),
               consult(Result),
               nl,write("Carregado com sucesso."),
               readchar(_),
               menu(1,Nome).

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


    ver_cliente (Nome) :- cliente (_, Nome, _).
     
    ver_livro (Nome)   :- livro (_, Nome, _).


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


    add_livro :-   clearwindow,nl,
                   write("Adicionar Livro"),nl,
                   write("-----------------"),nl,
                   write("Nome: "),
                   readln(Nome),nl,
                   not(ver_livro(Nome)),
                   write("Genero: "),
                   readln(Genero),
                   qtd_livros(COD),
                   COD1 = COD+1,
                   assertz(livro(COD1,Nome,Genero)),
                   nl,write("Adicionado com sucesso."),
                   readchar(_),!.

    add_livro :-   write("Livro ja existe."),nl,
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


    rem_livro   :- clearwindow,nl,
                   write("Remover Livro"),nl,
                   write("-----------------"),nl,
                   write("Nome: "),
                   readln(Nome),nl,
                   retract(livro(_,Nome,_)),
                   /* PARA NAO ATRAPALHAR O COD AUTO */
                   assertz(livro(0," "," ")),
                   nl,write("Removido com sucesso."),
                   readchar(_),!.

    rem_livro   :- write("Livro nao encontrado."),nl,
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


    bus_livro   :- clearwindow,nl,
                   write("Buscar Livro"),nl,
                   write("-----------------"),nl,
                   write("Nome: "),
                   readln(Nome),nl,
                   livro(COD,Nome,Genero),
                   write("Codigo: ",COD),nl,
                   write("  Nome: ",Nome),nl,
                   write("Genero: ",Genero),nl,
                   nl,write("Tecle para continuar..."),
                   readchar(_),!.

    bus_livro   :- write("Cliente nao encontrado."),nl,
                   nl,write("Tecle para continuar..."),
                   readchar(_).


    imprime_Clientes([]) :- readchar(_).

    imprime_Clientes([Cliente|Clientes]) :-
                   cliente(COD,Cliente,Idade),
                   write("  COD: ",COD),nl,
                   write(" Nome: ",Cliente),nl,
                   write("Idade: ",Idade),nl,
                   write("--------------"),nl,
                   imprime_Clientes(Clientes).


    imprime_Livros([]) :- readchar(_).

    imprime_Livros([Livro|Livros]) :-
                   livro(COD,Livro,Genero),
                   write("  COD: ",COD),nl,
                   write(" Nome: ",Livro),nl,
                   write("Genero: ",Genero),nl,
                   write("--------------"),nl,
                   imprime_Livros(Livros).


    lista_clientes :- findall(X,cliente(_,X,_),Clientes),
                      clearwindow,
                      write(" Clientes "),nl,
                      write("=========="),nl,nl,
                      imprime_Clientes(Clientes).


    lista_livros   :- findall(X,livro(_,X,_),Livros),
                      clearwindow,
                      write(" Livros "),nl,
                      write("=========="),nl,nl,
                      imprime_Livros(Livros).


    pegar :- clearwindow,nl,
             write("Cod Cliente: "),nl,
             write("> "),
             readInt(CodCliente),
             write("Cod Livro: "),nl,
             write("> "),
             readInt(CodLivro),
             write("Data: "),nl,
             write("> "),
             readln(Data),
             assertz(emprestimo(CodCliente,CodLivro,Data)).

    pegar :- write("Registo ja inserido"),nl,
             readchar(_).

    devolver.

    log_cliente.
    log_livro.

    processa(0).

    processa(1) :- add_cliente.
    processa(2) :- add_livro.

    processa(3) :- bus_cliente.
    processa(4) :- bus_livro.
    
    processa(5) :- rem_cliente.
    processa(6) :- rem_livro.

    processa(7) :- lista_clientes.
    processa(8) :- lista_livros.

    processa(9)  :- log_cliente.
    processa(10) :- log_livro.
    
    processa(11) :- pegar.
    processa(12) :- devolver.

Goal
    menu(0,_).
