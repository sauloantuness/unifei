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

         livro (                  cod_livro,    titulo,  genero)
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

    log_cliente (integer).
    log_livro.

    imp_clientes    (lista_int).
    imp_livros      (lista_int).
    imp_emprestimos (lista_int).

    ver_cliente (string)
    ver_livro   (string)

    qtd_clientes    (integer)
    qtd_livros      (integer)
    qtd_emprestimos (integer)

    qtd (lista_int, integer)

    pegar.
    devolver.

    processa (integer).
    boot     (integer).
    menu     (integer, string).
  
    rep (string, integer).       /*Repete*/
    cab (string).                /*Cabeçalho*/
    opc (lista_str, integer).    /*Opções*/
    rod (string).                /*Rodape*/
    
    le_i (string,integer).
    le_s (string,string).

Clauses

    opc([],_) :- !.
    opc([S|L],N) :- 
            write("  ", N, " - ", S),nl,
            N1 = N + 1,
            opc(L,N1).
                    
    rep(_,0) :- !.
    rep(C,N) :- 
            write(C), 
            N1 = N-1,
            rep(C,N1). 

    le_i(M,I) :-
            write(M), readInt(I).

    le_s(M,S) :-
            write(M), readln(S).
  
    cab(Titulo) :-  
            str_len(Titulo,T),
            N = (24 - T)/2 ,
            clearwindow,nl,
            rep(" ", N),
            write(Titulo),nl,
            rep("-", 24).

    rod(Mensagem) :-
            nl,write(Mensagem),
            readchar(_).

    qtd([],0) :- !.
    qtd([_|L],N) :- 
            qtd(L,N2), 
            N = N2 + 1.                

    qtd_clientes(N) :- 
            findall(X,cliente(X,_,_),L),
            qtd(L,N).

    qtd_livros(N) :-  
            findall(X,livro(X,_,_),L),
            qtd(L,N).                       

    qtd_emprestimos(N) :- 
            findall(X,emprestimo(X, _, _, _),L),
            qtd(L,N).


    processa(0) :- !.

    processa(1) :- add_cliente.
    processa(2) :- add_livro.

    processa(3) :- bus_cliente.
    processa(4) :- bus_livro.
    
    processa(5) :- rem_cliente.
    processa(6) :- rem_livro.

    processa(7) :- lis_clientes.
    processa(8) :- lis_livros.

    processa(9)  :- log_cliente(0).
    processa(10) :- log_livro.
    
    processa(11) :- pegar.
    processa(12) :- devolver.


    menu(0,_) :- 
            cab("BIBLIOTECA MAT014"),
            opc(["Nova","Carregar","Apagar"],1),
            opc(["Sair"],0),
            le_i("> ",Op),
            boot(Op).

    menu(1,Nome) :- 
            Nome = Nome,
            cab(Nome),

            write("Adicionar:"),nl,
            opc(["Cliente","Livro"],1),nl,
            
            write("Buscar:"),nl,
            opc(["Cliente","Livro"],3),nl,

            write("Remover:"),nl,
            opc(["Cliente","Livro"],5),nl,

            write("Listar:"),nl,
            opc(["Clientes","Livros"],7),nl,
            
            write("Relatorio:"),nl,
            opc(["Cliente","Livro"],9),nl,
            
            write("Emprestimo:"),nl,
            opc(["Pegar","Devolver"],11),nl,
            
            opc(["Sair"],0),nl,
            le_i("> ",Op),

            processa(Op),

            Op <> 0,
            menu(1,Nome).

    menu(1,Nome) :- 
            Nome = Nome,
            save(Nome),!.

    boot(0) :- !.

    boot(1) :- 
            cab("Nova Biblioteca"),
            le_s("Nome: ",Nome),
            save(Nome),
            rod("Criado com sucesso"),
            menu(1,Nome).
    
    boot(2) :- 
            cab("Carregar Biblioteca"),
            le_s("Nome: ",Nome),
            consult(Nome),
            rod("Carregado com sucesso."),
            menu(1,Nome).

    boot(3) :- 
            cab("Apagar Biblioteca"),
            le_s("Nome: ",Nome),
            deletefile(Nome),
            rod("Apagado com sucesso."),
            menu(0,_).

    ver_cliente(Nome) :- 
            cliente (_, Nome, _).
     
    ver_livro(Nome) :- 
            livro (_, Nome, _).

    add_cliente() :- 
            cab("Adicionar Cliente"),
            le_s("Nome: ", Nome),
            not(ver_cliente(Nome)),
            le_i("Idade: ", Idade),
            qtd_clientes(COD),
            COD1 = COD+1,
            assertz(cliente(COD1,Nome,Idade)),
            rod("Adicionado com sucesso.").

    add_cliente() :- 
            write("Cliente ja existe."),nl,
            rod("Tecle para continuar...").

    add_livro() :-
            cab("Adicionar Livro"),
            le_s("Nome: ",Nome),          
            not(ver_livro(Nome)),
            le_s("Genero: ",Genero),
            qtd_livros(COD),
            COD1 = COD+1,
            assertz(livro(COD1,Nome,Genero)),
            rod("Adicionado com sucesso."),!.

    add_livro() :-   
            write("Livro ja existe."),nl,
            rod("Tecle para continuar...").


    rem_cliente() :- 
            cab("Remover Cliente"),
            le_s("Nome: ",Nome),          
            retract(cliente(_,Nome,_)),
            /* PARA NAO ATRAPALHAR O COD AUTO */
            assertz(cliente(0," ",0)),
            rod("Removido com sucesso."),!.

    rem_cliente() :- 
            write("Cliente nao encontrado."),nl,
            rod("Tecle para continuar...").


    rem_livro() :- 
            rod("Remover Livro"),
            le_s("Nome: ",Nome),          
            retract(livro(_,Nome,_)),
            /* PARA NAO ATRAPALHAR O COD AUTO */
            assertz(livro(0," "," ")),
            rod("Removido com sucesso."),!.
 
    rem_livro() :- 
            write("Livro nao encontrado."),nl,
            rod("Tecle para continuar...").

    bus_cliente() :- 
            cab("Buscar Cliente"),
            le_s("Nome: ",Nome),          
            cliente(COD,Nome,Idade),nl,
            write("Codigo: ",COD),nl,
            write("  Nome: ",Nome),nl,
            write(" Idade: ",Idade),nl,
            rod("Tecle para continuar..."),!.
        
    bus_cliente() :- 
            write("Cliente nao encontrado."),nl,
            rod("Tecle para continuar...").

    bus_livro() :- 
            cab("Buscar Livro"),
            le_s("Nome: ",Nome),          
            livro(COD,Nome,Genero),nl,
            write("Codigo: ",COD),nl,
            write("  Nome: ",Nome),nl,
            write("Genero: ",Genero),nl,
            rod("Tecle para continuar..."),!.
               
    bus_livro() :- 
            write("Cliente nao encontrado."),nl,
            rod("Tecle para continuar...").

    imp_clientes([]) :- !.

    imp_clientes([0|CodClientes]) :- imp_clientes(CodClientes).

    imp_clientes([CodCliente|CodClientes]) :-
            cliente(CodCliente,Nome,Idade),
            write("  COD: ",CodCliente),nl,
            write(" Nome: ",Nome),nl,
            write("Idade: ",Idade),nl,
            write("--------------"),nl,
            imp_clientes(CodClientes).
 

    imp_livros([]) :- !.

    imp_livros([0|CodLivros]) :- imp_clientes(CodLivros).

    imp_livros([CodLivro|CodLivros]) :-
            livro(CodLivro,Titulo,Genero),
            write("   COD: ",CodLivro),nl,
            write("  Nome: ",Titulo),nl,
            write("Genero: ",Genero),nl,
            write("--------------"),nl,
            imp_livros(Livros).

    imp_emprestimos([]) :- !.

    imp_emprestimos([Emprestimo|Emprestimos]) :-
            emprestimo(Emprestimo,_,CodLivro,Data),
            livro(CodLivro,Titulo,_),
            write("   COD: ",Emprestimo),nl,
            write("  Nome: ",Titulo),nl,
            write("  Data: ",Data),nl,
            write("--------------"),nl,
            imp_emprestimos(Emprestimos).



    lis_clientes() :- 
            cab("Clientes"),
            findall(X,cliente(X,_,_),CodClientes),
            imp_clientes(CodClientes),
            rod("Tecle para continuar.").


    lis_livros() :- 
            cab("Livros"),
            findall(X,livro(X,_,_),CodLivros),
            imp_livros(CodLivros),
            rod("Tecle para continuar.").


    pegar() :- 
            cab("Pegar Livro"),
            le_i("Cod Cliente: ",CodCliente),
            le_i("Cod Livro: ",CodLivro),
            le_s("Data: ",Data),
            qtd_emprestimos(COD),
            COD1 = COD + 1,
            assertz(emprestimo(COD1,CodCliente,CodLivro,Data)),
            rod("Adicionado com sucesso."),!.

    pegar() :- 
            write("Registo ja inserido"),nl,
            rod("Tecle para continuar..."),!.

    devolver.


    log_cliente(0) :- 
            cab("Log Cliente"),
            opc(["Codigo","Nome"],1),
            le_i("> ",Op),
            log_cliente(Op).

    log_cliente(1) :-
            le_i("Informe o Codigo: ",CodCliente),
            cliente(CodCliente,Nome,Idade),
            cab("Log Cliente"),
            write("  COD: ",CodCliente),nl,
            write(" Nome: ",Nome),nl,
            write("Idade: ",Idade),nl,nl,
            findall(X,emprestimo(X,CodCliente,_,_),CodLivros),
            qtd(CodLivros,Qtd),
            write("Emprestimos: ", Qtd),nl,nl,
            imp_emprestimos(CodLivros),
            rod("Tecle para continuar."),!.

    log_cliente(1) :- 
            rod("Codigo Invalido.").

    log_cliente(2) :-
            le_s("Informe o Nome: ",Nome),
            cliente(CodCliente,Nome,Idade),
            cab("Log Cliente"),
            write("  COD: ",CodCliente),nl,
            write(" Nome: ",Nome),nl,
            write("Idade: ",Idade),nl,nl,
            findall(X,emprestimo(X,CodCliente,_,_),CodLivros),
            qtd(CodLivros,Qtd),
            write("Emprestimos: ", Qtd),nl,nl,
            imp_emprestimos(CodLivros),
            rod("Tecle para continuar."),!.

    log_cliente(2) :- 
            rod("Nome Invalido.").

    log_livro.

Goal

    menu(0,_).
