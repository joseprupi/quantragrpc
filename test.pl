list_member(X, [X|_]).
list_member(X, [_|TAIL]) :-
    list_member(X, TAIL).

list_length([], 0).
list_length([_|TAIL], N) :-
    list_length(TAIL, N1),
    N is N1+1.

list_concat([H1|T1],[H2|T2],L) :- list_concat(H1|L1,L2,L) 