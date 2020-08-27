question_one_s(a,10).
question_one_s(b,5).
question_one_s(c,10).
question_one_b(a,5).
question_one_b(b,3).
question_one_b(c,10).

question_two_s(a,10).
question_two_s(b,5).
question_two_s(c,8).
question_two_b(a,10).
question_two_b(b,10).
question_two_b(c,8).

question_three_s(a,3).
question_three_s(b,10).
question_three_s(c,10).
question_three_b(a,10).
question_three_b(b,10).
question_three_b(c,10).

question_four_s(a,10).
question_four_s(b,5).
question_four_b(a,5).
question_four_b(b,10).

question_five_s(a,10).
question_five_s(b,0).
question_five_s(c,10).
question_five_s(d,10).
question_five_b(a,0).
question_five_b(b,10).
question_five_b(c,0).
question_five_b(d,0).

question_six(a,2).
question_six(b,4).
question_six(c,10).
question_six(d,10).
question_six(e,4).
question_six(f,10).

question_sev(a,10).
question_sev(b,10).
question_sev(c,10).
question_sev(d,20).
question_sev(e,0).

expert_system :-
    write("-------Welcome to expert System---------"),nl,
    write("Please enter your name : "),nl,
    read(Name),
    write("Hello !"),write(Name),write(" Are you confused in choosing your carrier ?"),nl,nl,
    write("If Yes, then we are here to help you."),nl,
    write("You just need to answer the following questions honesty to make this system helpful for you"),nl,nl,nl,

    write("Did you ever tried to do following in your childhood just for the sake of curosity ?"),nl,
    write("a. Opened your toys / always curious to see inside"),nl,
    write("b. Used to play with plants / always Curious about how nature works"),nl,
    write("c. I was just curious science"),nl,nl,
    read(X),nl,
    question_one_s(X,Y),
    question_one_b(X,Yb),
    Z is Y,
    Zs is Yb,

    write("Do you like complex mathematic/logical problems ?"),nl,
    write("a. Very Much"),nl,
    write("b. Not my fav. part"),nl,
    write("c. No / sometime used to solve in school"),nl,
    read(X1),nl,
    question_two_s(X1,Y1),
    question_two_b(X1,Y1s),
    Z1 is Z + Y1,
    Z1s is Zs + Y1s,

    write("what do you think is hard to for you ?"),nl,
    write("a. Learning a long lesson with lengthy words where most of the times you just need to mug up things."),nl,
    write("b. Continuously sitting of 6-8 hours and solving some deep concepts."),nl,
    write("c. I can do both."),nl,
    read(X2),nl,
    question_three_s(X2,Y2),
    question_three_b(X2,Y2s),
    Z2 is Z1 + Y2,
    Z2s is Z1s + Y2s,

    write("In which field you are interested in ?"),nl,
    write("a. Solving real world problems and creating new apps and softwares"),nl,
    write("b. Want to help others in medical field"),nl,
    read(X3),nl,
    question_four_s(X3,Y3),
    question_four_b(X3,Y3s),
    Z3 is Z2 + Y3,
    Z3s is Z2s + Y3s,

    write("Which Subject is your biggest strength ?"),nl,nl,
    write("a. Physics"),nl,
    write("b. Biology"),nl,
    write("c. Physics and Mathematics"),nl,
    write("d. Mathematics"),nl,
    read(Xd),nl,
    question_five_s(Xd,Yd),
    question_five_b(Xd,Ydb),
    Zds is Z3 + Yd,
    Zdbs is Z3s + Ydb,
    Zdbsm is (Zdbs/50)*100,
    Z7 is (Zds/50)*100,
    write("Do you have computer ?"),nl,
    write("<yes/no>"),nl,
    read(X4),nl,
    (X4=yes
    ->  write("For which purpose you use computer most ?"),nl,
        write("a. Gaming"),nl,
        write("b. Internet"),nl,
        write("c. Programming"),nl,
        write("d. All"),nl,
        write("e. Only for a and b"),nl,
        write("f. Only for b and c"),nl,
        read(X5),nl,
        question_six(X5,Y4),
        Z4 is Zds + Y4,

        write("What do you know from following ?"),nl,
        write("a. CMD"),nl,
        write("b. Task Manager"),nl,
        write("c. Windows"),nl,
        write("d. OS"),nl,
        write("e. all"),nl,
        read(X6),nl,
        question_sev(X6,Y5),
        Z5 is Z4+Y5,
        Z6 is (Z5/70)*100,
        write("-------------------------------------------------------------------------------------"),nl,nl,
        write(Name),write(" we have you results..."),nl,nl,
        write("These are the score of your intrests"),nl,
        write("Engineering : "),write(Z6),nl,
        write("Medical : "),write(Zdbsm)
     ;
        write("-------------------------------------------------------------------------------------"),nl,nl,
        write(Name),write(" we have you results..."),nl,nl,
        write("These are the score of your intrests"),nl,
        write("Engineering : "),write(Z7),nl,
        write("Medical : "),write(Zdbsm)
    ).














