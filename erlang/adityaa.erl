-module(listUtil).
-export([listHead/1]).

listHead (M) when is_list (M), M =/=[]->
	[Head | _ ] = M,
	Head;
	
listHead (_) ->
	io:format ("Invalid Argument").