Domains

    cod_emprestimo = integer
    cod_cliente    = integer
    cod_livro      = integer
    idade          = integer
    titulo         = string
    genero         = string
    nome           = string
    data           = string    

    lista_str   = string*
    lista_int   = integer*


Database

         livro (                cod_livro,      titulo,  genero)
       cliente (                cod_cliente,      nome,  idade)
    emprestimo (cod_emprestimo, cod_cliente, cod_livro,  data)


Predicates

    add_cliente.
    rem_cliente.
    bus_cliente.

    add_livro.
    bus_livro.
    rem_livro.

    lis_clientes.
    lis_livros.

    log_cliente.
    log_livro.

    imp_clientes    (lista_str).
    imp_livros      (lista_str).
    imp_emprestimos (lista_int).

    ver_cliente (string)
    ver_livro   (string)

    qtd_clientes    (integer)
    qtd_livros      (integer)
    qtd_emprestimos (integer)

    qtd (lista_int, integer)

    pegar.
    devolver.

    processa (integer)
    boot     (integer)
    menu     (integer, string)


Clauses

    qtd([],0).
    qtd([_|L],N) :- qtd(L,N2), N = N2 + 1.                

    qtd_clientes(N) :- findall(X,cliente(X,_,_),L),
                       qtd(L,N).

    qtd_livros(N) :- findall(X,livro(X,_,_),L),
                       qtd(L,N).                       

    qtd_emprestimos(N) :- findall(X,emprestimo(X, _, _, _),L),
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
               save(Nome),
               nl,write("Criado com sucesso."),
               readchar(_),
               menu(1,Nome).
    
    boot(2) :- clearwindow, nl,
               write("  Carregar Locadora  "),nl,
               write("---------------------"),nl,
               write("Nome: "),
               readln(Nome),
               consult(Nome),
               nl,write("Carregado com sucesso."),
               readchar(_),
               menu(1,Nome).

    boot(3) :- clearwindow, nl,
               write("   Apagar Locadora   "),nl,
               write("---------------------"),nl,
               write("Nome: "),
               readln(Nome),
               deletefile(Nome),
               nl,write("Apagado com sucesso."),
               readchar(_),
               menu(0,_).



    ver_cliente (Nome) :- cliente (_, Nome, _).
     
    ver_livro (Nome) :- livro (_, Nome, _).


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


    imp_clientes([]) :- readchar(_).

    imp_clientes([Cliente|Clientes]) :-
                   cliente(COD,Cliente,Idade),
                   write("  COD: ",COD),nl,
                   write(" Nome: ",Cliente),nl,
                   write("Idade: ",Idade),nl,
                   write("--------------"),nl,
                   imp_clientes(Clientes).


    imp_livros([]) :- readchar(_).

    imp_livros([Livro|Livros]) :-
                   livro(COD,Livro,Genero),
                   write("   COD: ",COD),nl,
                   write("  Nome: ",Livro),nl,
                   write("Genero: ",Genero),nl,
                   write("--------------"),nl,
                   imp_livros(Livros).

    imp_emprestimos([]) :- readchar(_).

    imp_emprestimos([Emprestimo|Emprestimos]) :-
                   emprestimo(Emprestimo,_,CodLivro,Data),
                   livro(CodLivro,Titulo,_),
                   write("   COD: ",Emprestimo),nl,
                   write("  Nome: ",Titulo),nl,
                   write("  Data: ",Data),nl,
                   write("--------------"),nl,
                   imp_emprestimos(Emprestimos).




    lis_clientes :- findall(X,cliente(_,X,_),Clientes),
                      clearwindow,
                      write(" Clientes "),nl,
                      write("=========="),nl,nl,
                      imp_clientes(Clientes).


    lis_livros   :- findall(X,livro(_,X,_),Livros),
                      clearwindow,
                      write(" Livros "),nl,
                      write("=========="),nl,nl,
                      imp_livros(Livros).


    pegar :- clearwindow,nl,
             write("   Pegar Livro   "),nl,
             write("-----------------"),nl,
             write("Cod Cliente: "),
             readInt(CodCliente),
             write("Cod Livro: "),
             readInt(CodLivro),
             write("Data: "),
             readln(Data),
             qtd_emprestimos(COD),
             COD1 = COD+1,
             assertz(emprestimo(COD1,CodCliente,CodLivro,Data)),
             nl,write("Adicionado com sucesso."),
             readchar(_),!.

    pegar :- write("Registo ja inserido"),nl,
             nl,write("Tecle para continuar..."),
             readchar(_).

    devolver.


    log_cliente() :- clearwindow,nl,
                   write("  Log Cliente  "),nl,
                   write("---------------"),nl,
                   write("Nome: "),
                   readInt(CodCliente),
                   cliente(CodCliente,Nome,Idade),
                   clearwindow,nl,
                   write("  Log Cliente  "),nl,
                   write("---------------"),nl,
                   write("  COD: ",CodCliente),nl,
                   write(" Nome: ",Nome),nl,
                   write("Idade: ",Idade),nl,nl,
                   findall(X,emprestimo(X,CodCliente,_,_),CodLivros),
                   qtd(CodLivros,Qtd),
                   write("Emprestimos: ", Qtd),nl,

                   imp_emprestimos(CodLivros).


    log_livro.

    processa(0).

    processa(1) :- add_cliente.
    processa(2) :- add_livro.

    processa(3) :- bus_cliente.
    processa(4) :- bus_livro.
    
    processa(5) :- rem_cliente.
    processa(6) :- rem_livro.

    processa(7) :- lis_clientes.
    processa(8) :- lis_livros.

    processa(9)  :- log_cliente.
    processa(10) :- log_livro.
    
    processa(11) :- pegar.
    processa(12) :- devolver.

Goal
    menu(0,_).
