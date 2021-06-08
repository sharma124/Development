-module (functionWithGuards).
-export([isArgumentAnAtom/1]).

isArgumentAnAtom (N) when is_atom (N) ->
 true;
 
isArgumentAnAtom (_) ->
 false.