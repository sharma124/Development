package main

import "fmt"

type strc string

func main() {

	
	var str string
	var a strc
	str = "LTE1"
	a = "hero"

	switch str {
	
		case "LTE" :
			fmt.Println("LTE-go")
		case "UMTS" :
			fmt.Println("UMTS-go")
   }

   fmt.Println(a)
}
