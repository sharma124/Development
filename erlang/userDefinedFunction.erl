-module (userDefinedFunction).
-export ([conversion/1]).

convertToCM ({km, X}) ->
  {cm, X*100000}.

conversion ({meter, N}) ->
	Y = {km, N/1000},
	convertToCM (Y).

	
	