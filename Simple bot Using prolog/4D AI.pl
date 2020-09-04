nlp("how r you?","I am fine,How are you doing").
nlp("how are you?","I am fine,How are you doing").
nlp("how are u?","I am fine,How are you doing").
nlp("how r you?","I am fine,How are you doing").
nlp("how r u?","I am fine,How are you doing").
nlp("How are you doing?","I am fine,How are you doing").
nlp("How are you going?","I am fine,How are you doing").
nlp("i am sorry","That's okay. Everything is fine").
nlp("first year","Thats Good,You have great time to learn about programming").
nlp("second year","What have you done in First year").
nlp("ok! leave","Oh! you have point").
nlp("love","I like that too much").
nlp("create","I am a simple Bot,created by Chetan").
nlp("who are you?","I am a simple Bot,created by Chetan").
nlp("doing","Okay").
nlp("not good","Okay").
nlp("direct second year","ok! leave").
sw("fine","doing").
sw("good","doing").
sw("bad","doing").
sw("dsy","ok! leave").
sw("project","ok!leave").
sw("programming","love").
sw("computers","love").
sw("sorry","I am sorry").
sw("creator","create").


chat :-
    read_input.

read_input :-
    repeat,
    read_string(user_input, "\n", "\r\t ", _, Line1),
    string_lower(Line1,Line),
    process_input(Line).

process_input(Line) :-
    ( nlp(Line,Z)
    ->  writeln(Z),nl
    ;   split_string(Line," "," ",L),member(X,L),( sw(X,B)
                                                   ->  nlp(B,A),write(A)
                                                   ;   fail
                                                   )
    ).

process_input("quit") :-
    write('Finished'), nl,
    !, true.

