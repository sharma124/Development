-module(listUtil).
-export([listHead/1, listTail/1]).

listHead (M) when is_list (M), M =/=[]->
	[Head | _ ] = M,
	Head;
	
listHead (_) ->
	io:format ("Invalid Argument"),
	ok.

listTail ([M]) ->
	M;
listTail (M) when is_list (M), M=/=[] ->
	[_ | Tail] = M,
	listTail(Tail);
listTail (_) ->
	io:format("Inavlid Argument").