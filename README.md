# routerForSpeedrun
How to use it: \
Drag and drop the input file on the program.
The input file contain the steps in the following format : 

stepName1 nbrOfPrerequisites prerequisite1 prerequisite2 ... \
stepName2 nbrOfPrerequisites prerequisite1 prerequisite2 ... \
stepName3 nbrOfPrerequisites prerequisite1 prerequisite2 ... \
...

requisites : the steps that need to be completed to complete this step

Example:
You need to go to the boss, but before, you need the sword, and to have the sword, you need a letter and a key. The file should be as follow:
(The order doesn't matter)

sword 2 key letter \
boss 1 sword \
letter 0 \
key 0



Route:

letter \
key \
sword \
boss
