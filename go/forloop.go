package main

import "fmt"

func myfunc () bool {

	i := true
	j := false

	return i && j
}

func main() {

	var iplist [2]string
	//iplist := make([]string, "")
	iplist[0] = "192.168.1.1"
	iplist[1] = "192.168.2.1"
	//var iplist ["192.168.1.1", "192.168.2.1"]string

	for i := range iplist {
		fmt.Println(i)
	}

	if myfunc() {
	
		fmt.Println("true returned")
	}
	fmt.Println("vim-go")
}
