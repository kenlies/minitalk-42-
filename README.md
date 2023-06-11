# minitalk
## My hive (42) school project for minitalk

This was a project in which we had to create a simple communication system between a client and a server using PIDs and signals.

At school we have come to a consensus that we don't necessarily need bonus files for bonuses if moulinette (the robot) isn't assigned for evaluations -> code for bonuses can be in mandatory files. 

First the server must be launched -> it prints its PID & starts listening for signals -> from other terminal: ./client [PID] [MESSAGE] -> enter

Now the server should print the message sent by the client. Supports unicode characters & the client prints out an acknowledgement message sent by the server once message is printed on the server.

I've included the subject as always.

use:


     ./server
     ./client [server PID] [message]
examples:
      
      
     ./server
      pid: 55555
      Waiting...
      
     ./client 55555 "Hello there general kenobi"

<img width="622" alt="Screen Shot 2023-06-11 at 1 38 45 PM" src="https://github.com/kenlies/minitalk-42-/assets/97135325/7e3598d2-dc45-4f62-aabe-9d2fd0ee6917">
