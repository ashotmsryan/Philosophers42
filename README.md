# Philosophers42

One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.

The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
There are also forks on the table. There are as many forks as philosophers.
Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.

Every philosopher needs to eat and should never starve.
Philosophers don’t speak with each other.
Philosophers don’t know if another philosopher is about to die.
No need to say that philosophers should avoid dying!

This project challenges to implement a solution using threads, mutexes
to manage the dining philosophers' resource-sharing problem.
This project is a good way to learn about multithreading and its inadequate sides))

<h3>compile and run</h3>
Compile the project using "make", then run command line below

```
./philo 5 800 200 100 7
```
5 is the quantity of philosophers<br>
800 is life time of philosopher<br>
200 is eating time<br>
100 if sleeping time<br>
7 is number of eating for each philosopher<br>
</br>
-Test with 5 800 200 200, no one should die!<br>
-Test with 4 410 200 200, no one should die!<br>
-Test with 4 310 200 100, a philasopher should die!<br>
