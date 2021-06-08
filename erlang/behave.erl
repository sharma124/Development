-module(behave).
-export([start/0, receiveLoop/0]).

start() ->
  spawn(behave, receiveLoop, []).

receiveLoop() ->
 receive
	{Pid, hello} ->
		io:format("Hello ~p", [Pid])
 end,

 receiveLoop().
