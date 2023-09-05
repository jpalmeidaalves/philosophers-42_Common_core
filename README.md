## Philosophers-42_Common_core
#### Understanding the problem
Multiple philosophers are seated at a round table.
In the center of the table, there is a bowl of spaghetti.
The philosophers take turns either eating, thinking, or sleeping.
While they eat, they cannot think or sleep. While thinking, they cannot eat or sleep. While sleeping, they cannot eat or think.
There are forks on the table, one for each philosopher.
To eat, each philosopher uses both the right and left forks, holding one in each hand.
After finishing a meal, a philosopher places their forks back on the table and starts sleeping. Upon awakening, they resume thinking. The simulation continues until a philosopher dies of starvation.
It is crucial that every philosopher gets to eat and does not starve.
Philosophers do not communicate with each other.
Philosophers are unaware if another philosopher is close to starving.
Needless to say, philosophers should strive to avoid starving.
### Rules
* Global variables are prohibited.
* Each program should accept specific command-line arguments, including the number of philosophers, time limits for various actions, and an optional limit on the number of times each philosopher must eat.
* Philosophers are numbered from 1 to the total number of philosophers, with philosopher 1 adjacent to philosopher N, where N is the total number of philosophers.
* The programs must log philosopher state changes, such as taking a fork, eating, sleeping, thinking, and dying, with timestamps in milliseconds and the corresponding philosopher number.
* Messages for philosopher state changes should be clearly separated and not mixed with other messages.
* Announcements of a philosopher's death should occur within 10 milliseconds of the actual event.
* Your programs must be designed to prevent philosophers from starving and should not encounter data races.
### Mandatory
#### The specific rules for the mandatory part are:
• Each philosopher should be a thread.
• There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.
• To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.
### Bonus
The program of the bonus part takes the same arguments as the mandatory program.
It has to comply with the requirements of the Global rules chapter.
The specific rules for the bonus part are:
• All the forks are put in the middle of the table.
• They have no states in memory but the number of available forks is represented by
a semaphore.
• Each philosopher should be a process. But the main process should not be a
philosopher.
